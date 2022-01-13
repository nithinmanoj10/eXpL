!/bin/zsh

cd '/mnt/d/Nithin Stuff/Sem 6/Compiler Lab/Compiler-Lab-NITC'

clear
echo "📁 Pushing Files ➡ nithinmanoj10/Compiler-Lab-NITC ...\n"

# Adding all the files
git add -A

git status

printf "\n📄 Enter Commit Message: "
read commitMessage

git commit -m "$commitMessage"

git push origin master

printf "nithinmanoj10\n"
printf "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\n"
