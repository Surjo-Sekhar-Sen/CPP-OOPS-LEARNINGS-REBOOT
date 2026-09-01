## 1. Class Structure & Object Lifecycle

C++ me jab ek class define hoti hai, toh usme 4 core building blocks hote hain:

1. **Attributes / State:** Data members (e.g., `id`, `age`, `name`).
    
2. **Behavior / Methods:** Member functions jo data par operate karte hain.
    
3. **Constructor (`ctor`):** Object ke birth par call hota hai (Initialization ke liye).
    
4. **Destructor (`dtor`):** Object ke death / scope out hone par call hota hai (Cleanup ke liye).

Object Lifecycle: [ Instantiation ] ---> [ Constructor Called ] ---> [ Methods Execution ] ---> [ Scope Out / delete ] ---> [ Destructor Called ]

## 2. Constructors (The 3 Forms)

Constructor ek special member function hai:

- Iska **naam Class ke naam ke exact same** hota hai.
    
- Iska **koi return type nahi hota** (`void` bhi nahi).
    
- Hamesha `public` section me declare kiya jata hai (unless design pattern me intentionally private rakhein).

![[Pasted image 20260901223027.png]]

![[Pasted image 20260901223050.png]]

![[Pasted image 20260902001132.png]]

![[Pasted image 20260902001218.png]]

## ==IMPORTANT!!==

![[Pasted image 20260902001840.png]]

![[Pasted image 20260902001940.png]]

![[Pasted image 20260902002137.png]]

## ==IS CLASS INSIDE CLASS ALLOWED??==

![[Pasted image 20260902003645.png]]

![[Pasted image 20260902003702.png]]

![[Pasted image 20260902003715.png]]

## 3. The `this` Pointer (Under the Hood)

Interview me pucha jane wala classic sawaal: **"What is `this` pointer in C++?"**

- `this` ek **constant pointer (`Student* const this`)** hota hai jo current calling object ke memory address ko hold karta hai.
    
- Jab aap `s1.study()` call karte ho, compiler internally function ko aise pass karta hai:

![[Pasted image 20260901223221.png]]

- **Use Cases of `this`:**
    
    1. **Name Ambiguity Resolve Karna:** Jab parameter ka naam aur class member variable ka naam same ho (`this->name = name`).
        
    2. **Method Chaining:** Object ka reference return karna (`return *this;`).
        

## 4. Copy Constructor: Deep Copy vs Shallow Copy & The `&` Pass-by-Reference Trap

Copy constructor ka signature dhyan se dekho:

![[Pasted image 20260901223247.png]]

### Interview Question 1: Copy constructor me `&` (Pass-by-Reference) mandatory kyu hai?

Agar aap `&` hata doge:

![[Pasted image 20260901223345.png]]

- C++ me pass-by-value karte waqt argument ki **copy** banti hai.
    
- Copy banane ke liye compiler **Copy Constructor** ko call karega.
    
- Wo Copy Constructor dobara pass-by-value dekhega aur fir se Copy Constructor ko call karega.
    
- Isse **Infinite Recursive Loop (Stack Overflow)** ban jayega. Isliye compiler bina `&` ke code compile hi nahi karta.
    

### Interview Question 2: `const` kyu lagate hain?

Taaki source object (`srcObj`) galti se modify na ho jaye (Read-only guarantee).

## 5. Stack vs Heap Allocation & The Dynamic Memory Lifecycle

Video me dikhaya gaya ki memory allocation do tareeqon se hoti hai:

![[Pasted image 20260901223444.png]]

### Destruction of Heap Pointers inside Destructor:

Agar class ke andar dynamic memory allocate hui ho:

![[Pasted image 20260901223508.png]]

## 6. Execution Flow & Output Trace (Mental Model)

Agar ye code chale:

![[Pasted image 20260901223538.png]]

- **Constructor Calling Order:** `A` pehle construct hoga, fir `B`.
    
- **Destructor Calling Order (Stack is LIFO - Last In First Out):** `B` pehle destroy hoga, fir `A`
