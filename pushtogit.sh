!/bin/zsh

cd '/mnt/d/Nithin Stuff/Sem 6/Compiler Lab/Compiler-Lab-NITC'

clear
echo "📁 Pushing Files ➡ nithinmanoj10/Compiler-Lab-NITC ...\n"

# Adding all the files
git add -A

printf '%.s─' $(seq 1 $(tput cols))
git status
printf '%.s─' $(seq 1 $(tput cols))

printf "\n📄 Enter Commit Message: "
read commitMessage
printf "\n"

printf '%.s─' $(seq 1 $(tput cols))
git commit -m "$commitMessage"
printf '%.s─' $(seq 1 $(tput cols))

# git push origin master

printf '%.s─' $(seq 1 $(tput cols))
printf "nithinmanoj10\n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\n" | git push origin master
printf '%.s─' $(seq 1 $(tput cols))
