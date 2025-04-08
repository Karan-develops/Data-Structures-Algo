1. If we do inorder traversal on BST we got elements in sorted order
2. Pass `prev by reference or make it global` when checking if a tree is a BST using inorder.
→ So you can compare previous node value across recursive calls.
3. Inorder Successor = leftmost node of right subtree
→ Used during deletion (2 children) or finding next higher value.
4. Inorder Predecessor = rightmost node of left subtree
→ Can also be used for deletion or previous smaller value.
5. To find kth smallest/largest, do inorder (or reverse inorder) and count nodes.
6. If given a sorted array, use middle element as root to build a balanced BST.