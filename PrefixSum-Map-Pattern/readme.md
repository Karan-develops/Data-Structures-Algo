# 📊 Prefix Sum + Hash Map Pattern

This pattern is powerful when dealing with **range sums** in arrays or matrices, especially when you're looking to **count the number of subarrays/submatrices** that sum to a target value.

---

## 🧠 Key Idea

Instead of recomputing sums repeatedly, **store cumulative sums** and use a **hash map** to track how often a certain prefix sum has occurred.

This allows us to compute in `O(n)` for 1D and `O(n² * m)` for 2D.

---

## 🧮 Formula
- Initialize map with `{0: 1}` OR `Other Value based on Question` to handle subarrays starting at index 0.
Let:
- `currSum` be the sum from the beginning up to current index
- `target` be the desired sum

If `currSum - target` exists in the hash map, it means there exists a previous prefix sum that can be removed to form a valid subarray:
