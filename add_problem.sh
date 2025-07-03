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
        display_name="$(echo "$display_name" | awk '{ print toupper(substr($0,1,1)) tolower(substr($0,2)) }')"
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

    # Collect all topic directories (excluding build, hidden, and problem folders)
    while IFS= read -r -d $'\0' dir; do
        topics+=("$dir")
    done < <(find "$rootPath" -maxdepth 1 -mindepth 1 -type d ! -name "build" ! -name ".*" ! -regex '.*/[0-9]{3}_.*' -print0)

    IFS=$'\n' sorted=($(printf "%s\n" "${topics[@]}" | sort))
    unset IFS

    # Initialize counters
    declare -A stats=( ["easy"]=0 ["medium"]=0 ["hard"]=0 ["unknown"]=0 )

    # Write main README
    {
        echo "# Leetcode Study Vault"
        echo
        echo "This repository was created as a way to deepen understanding of **algorithms** and **data structures** by solving problems from Leetcode."
        echo "Each solution is documented to serve as both a **reference** and a **personal learning log**."
        echo
        echo "It is structured in a way that makes it easy to review, revisit, and expand my problem-solving knowledge over time."
        echo
        echo "## Topics"
        echo
        for topic_path in "${sorted[@]}"; do
            topic_name=$(basename "$topic_path")
            echo "- [$topic_name](./$topic_name)"
        done
        echo
        echo "## Repository Structure"
        echo
        echo "Organized by topic (e.g., \`arrays\`, \`graph\`, \`dp\`). Each problem is in a numbered folder with a slug:"
        echo 
        echo  '```'
        echo "📁 arrays/"
        echo "  ├── 001_two_sum/"
        echo "  │   ├── solution.cpp"
        echo "  │   └── README.md"
        echo '```'
        echo
        echo "## How to Add a New Problem"
        echo "I created this script to help with documentation and repository organization. Here's how to use it:"
        echo
        echo "### 1. Make the script executable:"
        echo '```bash'
        echo "chmod +x add_problem.sh"
        echo '```'
        echo
        echo "### 2. Run it:"
        echo '```bash'
        echo "./add_problem.sh"
        echo '```'
        echo
        echo "It will prompt you for:"
        echo "- Category (e.g., \`arrays/binarysearch\`)"
        echo "- Problem title"
        echo "- Difficulty (optional)"
        echo
        echo "It then creates a folder with:"
        echo "- \`solution.cpp\`"
        echo "- \`README.md\`"
        echo "And updates all README files automatically."
        echo
    } > README.md
}

# ---------------- Main ----------------

read -p "Enter category (e.g., arrays/binarysearch): " category_path
category_path=$(echo "$category_path" | tr '[:upper:]' '[:lower:]')
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

# Create README.md
cat <<EOF > "$problem_path/README.md"
# $title

- 🧩 Problem link: [Leetcode](https://leetcode.com/problemset/all/)
- 🚦 Difficulty: $( [[ "$difficulty" == "easy" ]] && echo "🟢 Easy" || ([[ "$difficulty" == "medium" ]] && echo "🟡 Medium" || ([[ "$difficulty" == "hard" ]] && echo "🔴 Hard" || echo "(not specified)")))

## 💡 Approach
// notes about the solution, pseudocode, etc

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
