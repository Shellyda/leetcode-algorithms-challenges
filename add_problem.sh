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
    echo "# $(basename "$category_path" | sed -E 's/_/ /g' | awk '{ for(i=1;i<=NF;i++) $i=toupper(substr($i,1,1)) tolower(substr($i,2)); print }')" > "$category_path/README.md"
    echo "" >> "$category_path/README.md"
    echo "## Problems" >> "$category_path/README.md"
    echo "" >> "$category_path/README.md"

    for dir in $(ls -1 "$category_path" | grep -E '^[0-9]{3}_.+' | sort); do
        if [[ -d "$category_path/$dir" ]]; then
            display_name=$(echo "$dir" | sed -E 's/^[0-9]{3}_//' | sed -E 's/_/ /g' | awk '{ for(i=1;i<=NF;i++) $i=toupper(substr($i,1,1)) tolower(substr($i,2)); print }')
            echo "- [$display_name](./$dir)" >> "$category_path/README.md"
        fi
    done
}


update_parent_readme() {
    local category_path="$(dirname "$1")"
    [[ "$category_path" == "." ]] && return

    echo "# $(basename "$category_path" | sed -E 's/_/ /g' | awk '{ for(i=1;i<=NF;i++) $i=toupper(substr($i,1,1)) tolower(substr($i,2)); print }')" > "$category_path/README.md"
    echo "" >> "$category_path/README.md"
    echo "## Subtopics" >> "$category_path/README.md"
    echo "" >> "$category_path/README.md"

    local index=1
    for dir in $(ls -1 "$category_path" | grep -vE '^[0-9]{3}_' | sort); do
        if [[ -d "$category_path/$dir" ]]; then
            display_name=$(echo "$dir" | sed -E 's/_/ /g' | awk '{ for(i=1;i<=NF;i++) $i=toupper(substr($i,1,1)) tolower(substr($i,2)); print }')
            echo "$index. [$display_name](./$dir)" >> "$category_path/README.md"
            ((index++))
        fi
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

    # Write main README
    {
        echo
        echo '<p align="left">'
        echo '  <img src="https://img.shields.io/badge/Language-C++-blue.svg" />'
        echo '  <img src="https://img.shields.io/badge/Leetcode-Study-yellow.svg" />'
        echo '  <img src="https://img.shields.io/badge/Automated_README-✔️-success" />'
        echo '</p>'
        echo
        echo "# Leetcode Study Vault"
        echo
        echo "This repository was created as a way to deepen understanding of **algorithms** and **data structures** by solving problems from Leetcode."
        echo "Each solution is documented to serve as both a **reference** and a **personal learning log**."
        echo
        echo "> It is structured in a way that makes it easy to review, revisit, and expand my problem-solving knowledge over time."
        echo
        echo "## Topics"
        echo
        echo "1. [Arrays](./arrays)
              2. [Linked Lists](./linked_lists)
              3. [Recursion](./recursion)
              4. [Sorting](./sorting)
              5. [Binary Search](./binary_search)
              6. [Trees](./trees)
              7. [Backtracking](./backtracking)
              8. [Heap](./heap)
              9. [Hashing](./hashing)
              10. [Graphs](./graphs)
              11. [Dynamic Programming](./dynamic_programming)
              12. [Bit Manipulation](./bit_manipulation)"
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
        echo "  └── README.md"
        echo '```'
        echo
        echo "## Content Documentation: How to Add a New Problem"
        echo "I created this script to help with documentation and repository organization. Here's how to use it:"
        echo
        echo "#### 1. Make the script executable:"
        echo '```bash'
        echo "chmod +x add_problem.sh"
        echo '```'
        echo
        echo "#### 2. Run it:"
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
        echo "## Author info"
        echo "[![Leetcode](https://img.shields.io/badge/Leetcode-yellow?logo=Leetcode&logoColor=white)](https://leetcode.com/u/shellyda-barbosa)"
        echo "[![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?logo=linkedin&logoColor=white)](https://linkedin.com/in/shellyda-barbosa)"
        echo "> Made with dedication by [Shellyda](https://github.com/Shellyda)"
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
