# Project 2: This is a smart ware house system trying to increase my skill in smar pointers

## 🎯 Goal
---
Design a mini warehouse system that handles packages stored in storage units, and workers who move them — using smart pointers with correct, deliberate ownership semantics.

You’re building a system that models:

- Package → uniquely owned, lightweight objects (unique_ptr)

- StorageUnit → owns multiple packages

- Warehouse → owns multiple storage units (shared_ptr)

- Worker → can temporarily access packages via weak_ptr references