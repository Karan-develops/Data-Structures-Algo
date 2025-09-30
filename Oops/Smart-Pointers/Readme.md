### 🚀🚀 Smart pointers 🚀🚀

#### 1. Problems in raw pointers
```
- You have to manually delete memory.

- If you forget → memory leak.

- If you delete twice → crash.

- If exception occurs before delete → memory leak.
```

#### 2. Smart pointers are objects that manage memory automatically.

#### 3. They delete the object when it’s no longer needed, so you don’t have to remember.

#### 4. C++ has three main types:

| Pointer              | Use case                | How it works                                                                                           |
| -------------------- | ----------------------- | ------------------------------------------------------------------------------------------------------ |
| `unique_ptr<T>` | Exclusive ownership     | `Only one` pointer owns the object. Automatically deletes when goes out of scope.                        |
| `shared_ptr<T>` | Shared ownership        | Multiple pointers can point to the same object. Deletes automatically when the `last owner` is gone. |
| `weak_ptr<T>`   | Avoid cyclic references | Doesn’t count as ownership. Used with `shared_ptr` to prevent memory cycles.                           |

#### 5. Rule of thumb
```
- unique_ptr → default choice (fastest, safest).

- shared_ptr → when ownership is shared.

- weak_ptr → when you need a “weak” reference without keeping the object alive.
```