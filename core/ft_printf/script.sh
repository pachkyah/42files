# Step 2
git config -f .git/config --remove-section submodule.libft

# Step 3
git rm --cached libft

# Step 4
rm -rf libft

# Step 5
git add .gitmodules
git commit -m "Remove libft submodule"

# Step 6: Copy your libft files back manually, then
git add libft
git commit -m "Add libft as normal folder"
