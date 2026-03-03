static_cast - Compile-Time Type Conversion
safe, well-defined conversions between related types (eg. numerics)

reinterpret_cast - Bit-Level Reinterpretation
low-level, unsafe conversions by reinterpreting the bit pattern of one type as another (No actual conversion, just treats the same bits differently)

dynamic_cast - Runtime Type Checking
safe downcasting in polymorphic class hierarchies with runtime type checking. (Only works with polymorphic types (classes with at least one virtual function))