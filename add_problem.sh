#!/bin/bash

slugify() {
    echo "$1" | tr '[:upper:]' '[:lower:]' | sed -E 's/[^a-z0-9]+/_/g' | sed -E 's/^_+|_+$//g'
}

get_next_problem_number() {
    local category_path="$1"
    local max_num=0
    for dir in "$category_path"/*; do
        if [[ -d "$dir" && "$(basename "$dir")" =~ ^[0-9]{3}_ ]]; then
            num=$(echo "$(basename "$dir")" | cut -d'_' -f1)
            if ((10#$num > max_num)); then
                max_num=$((10#$num))
            fi
        fi
    done
    echo $((max_num + 1))
}

update_category_readme() {
    local category_path="$1"
    echo "# $(basename "$category_path")" > "$category_path/README.md"
    echo "" >> "$category_path/README.md"
    echo "## Problems" >> "$category_path/README.md"
    echo "" >> "$category_path/README.md"

    for dir in $(ls -1 "$category_path" | grep -E '^[0-9]{3}_.+' | sort); do
        display_name=$(echo "$dir" | sed -E 's/^[0-9]{3}_//' | tr '_' ' ')
        display_name="$(tr '[:lower:]' '[:upper:]' <<< ${display_name:0:1})${display_name:1}"
        echo "- [$display_name](./$dir)" >> "$category_path/README.md"
    done
}

update_parent_readme() {
    local category_path="$(dirname "$1")"
    [[ "$category_path" == "." ]] && return

    echo "# $(basename "$category_path")" > "$category_path/README.md"
    echo "" >> "$category_path/README.md"
    echo "## Subtopics" >> "$category_path/README.md"
    echo "" >> "$category_path/README.md"

    for dir in $(ls -1 "$category_path" | grep -vE '^[0-9]{3}_' | sort); do
        [[ -d "$category_path/$dir" ]] && echo "- [$dir](./$dir)" >> "$category_path/README.md"
    done
}

update_root_readme() {
    local rootPath="$(pwd)"
    local topics=()

    # Collect valid directories (exclude "build", hidden dirs, and dirs starting with 3-digit prefix)
    while IFS= read -r -d $'\0' dir; do
        name=$(basename "$dir")
        topics+=("$name")
    done < <(find "$rootPath" -maxdepth 1 -mindepth 1 -type d ! -name "build" ! -name ".*" ! -regex '.*/[0-9]{3}_.*' -print0)

    # Sort the topics array
    IFS=$'\n' sorted=($(sort <<<"${topics[*]}"))
    unset IFS

    # Initialize difficulty counters
    declare -A stats=( ["easy"]=0 ["medium"]=0 ["hard"]=0 ["unknown"]=0 )

    # Count problems by difficulty inside each topic
    for topic in "${sorted[@]}"; do
        for problem_dir in "$rootPath/$topic"/[0-9][0-9][0-9]_*/; do
            [[ -d "$problem_dir" ]] || continue
            difficulty="unknown"
            if [[ -f "$problem_dir/README.md" ]]; then
                # Search for line containing "Difficulty:" in problem README
                line=$(grep -i 'Difficulty:' "$problem_dir/README.md" | head -1)
                if [[ $line =~ Easy ]]; then
                    difficulty="easy"
                elif [[ $line =~ Medium ]]; then
                    difficulty="medium"
                elif [[ $line =~ Hard ]]; then
                    difficulty="hard"
                fi
            fi
            ((stats[$difficulty]++))
        done
    done

    local total=$((stats["easy"] + stats["medium"] + stats["hard"] + stats["unknown"]))

    # Write the root README.md
    {
        echo "# Leetcode Study Vault"
        echo
        echo "## Topics"
        echo
        for topic in "${sorted[@]}"; do
            echo "- [$topic](./$topic)"
        done

        echo
        echo "## 📊 Difficulty Breakdown"
        echo
        echo "| Difficulty | Count |"
        echo "|------------|-------|"
        echo "| 🟢 Easy    | ${stats["easy"]} |"
        echo "| 🟡 Medium  | ${stats["medium"]} |"
        echo "| 🔴 Hard    | ${stats["hard"]} |"
        echo "| ❔ Unknown | ${stats["unknown"]} |"
        echo "| **Total**  | $total |"
    } > README.md
}


# ------------- Main -----------------

read -p "Enter category (e.g., arrays/binarysearch): " category_path
read -p "Enter problem title: " title
read -p "Enter difficulty (easy/medium/hard) [optional]: " difficulty

slug=$(slugify "$title")
category_dir="$(pwd)/$category_path"

mkdir -p "$category_dir"

problem_num=$(get_next_problem_number "$category_dir")
folder_name=$(printf "%03d_%s" "$problem_num" "$slug")
problem_path="$category_dir/$folder_name"

mkdir -p "$problem_path"

# Create solution.cpp
cat <<EOF > "$problem_path/solution.cpp"
// $title

EOF

# Create README.md of the problem
cat <<EOF > "$problem_path/README.md"
# $title

- 🧩 Problem link: [Leetcode](https://leetcode.com/problemset/all/)
- 🚦 Difficulty: $( [[ "$difficulty" == "easy" ]] && echo "🟢 Easy" || ([[ "$difficulty" == "medium" ]] && echo "🟡 Medium" || ([[ "$difficulty" == "hard" ]] && echo "🔴 Hard" || echo "(not specified)")) )

## 💡 Approach

## 🕒 Time and Space Complexity
- Time: 
- Space: 

## ✅ Solution

\`\`\`cpp
// your code here
\`\`\`
EOF

update_category_readme "$category_dir"
update_parent_readme "$category_dir"
update_root_readme

echo "✅ Created: $problem_path"
