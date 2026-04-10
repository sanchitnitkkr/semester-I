| Feature                         | SCAN                              | C-SCAN                   | LOOK             | C-LOOK                       |
| ------------------------------- | --------------------------------- | ------------------------ | ---------------- | ---------------------------- |
| **Full Name**                   | Elevator Algorithm                | Circular SCAN            | LOOK Algorithm   | Circular LOOK                |
| **Movement Style**              | Back and forth                    | One direction (circular) | Back and forth   | One direction (circular)     |
| **Goes to disk end (0 / max)?** | ✅ Yes                             | ✅ Yes                    | ❌ No             | ❌ No                         |
| **Stops at last request?**      | ❌ No                              | ❌ No                     | ✅ Yes            | ✅ Yes                        |
| **Direction change**            | At disk ends                      | Never (wraps around)     | At last request  | Never (wraps around)         |
| **Jump behavior**               | ❌ No jump                         | ✅ Jumps from end → start | ❌ No jump        | ✅ Jumps last → first request |
| **Efficiency**                  | Medium                            | Better than SCAN         | Better than SCAN | Best among all               |
| **Seek time**                   | Higher (extra travel to ends)     | Moderate                 | Lower            | Lowest                       |
| **Uniform wait time**           | ❌ No                              | ✅ Yes                    | ❌ No             | ✅ Yes                        |
| **Starvation**                  | ❌ No                              | ❌ No                     | ❌ No             | ❌ No                         |
| **Head movement waste**         | High (goes to ends unnecessarily) | Medium                   | Low              | Very low                     |
| **Real-world usage**            | Rare now                          | Used in OS               | Common           | Very efficient systems       |
