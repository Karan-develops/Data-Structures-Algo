## Segment Tree 🌴

#### 1. An Efficient Data Structure that allow :
- Efficient Quering of `Interval/Range`.
- Efficient Quering of `Interval/Range`.

#### 2. Segment Tree is a `Binary Tree, Exactly 2 Children of Non-Leaf Nodes`
- `Leaf` Nodes Represents Single Element of an array.
- `Root` Node Represents entrire array `(Array's Sum)`.
- Other `(Non-Leaf)` Nodes Represents `Interval/Range` of an array (Like `prefix Sum` of a range).

#### 3. `Height` of Segment Tree is ` ciel(log(n)) `.

#### 4. Different Between `SubTree (Left & Right SubTree)` of any node is always less than equal to 1. Hence, it is `Balanced Binary Tree`.

#### 5. If there are `N` Elements in an array then `number of nodes` in segment tree of that array will be `Approx : 2*N`. Exactly `2*N` if the size is `power of 2`.

> ## Representation of Segment Tree

#### 1. We can also make Segment Tree like `TreeNode*` but representing Segment Tree in `Array` is best Practice.

#### 2. `ith` node's Left Child is at `2i+1` & Right Child is at `2i+2`.

> ## Building Segment Tree

#### 1. Firstly find `mid` of `ith` node.

#### 2. `ith` node's Left Child will have Indices from `l=0 & r=mid` and Right Child will have indices from `l=mid+1 & r=n-1`.

#### 3. Recursively Call to make `subtrees` to make the whole Segment Tree.

#### 4. Now see `intro.cpp`