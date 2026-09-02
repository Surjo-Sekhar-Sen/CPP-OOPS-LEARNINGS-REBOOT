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

## ==ANOTHER WAY: DEFAULT CONSTRUCTOR CHANGES!!==

![[Pasted image 20260902192458.png]]

![[Pasted image 20260902192532.png]]

## ==HOW DID THIS VALUE COME??==

![[Pasted image 20260902192803.png]]

![[Pasted image 20260902192935.png]]

![[Pasted image 20260902193012.png]]

## ==CONSTRUCTOR CREATION'S MODERN WAY:==

## Constructor Writing ka Modern & Recommended Way: Initializer List

C++ me constructor body ke andar assign karne se better hota hai **Member Initializer List** use karna:

![[Pasted image 20260902193141.png]]

## ==PARAMETERISED CONSTRUCTORS==

![[Pasted image 20260902202546.png]]

![[Pasted image 20260902202610.png]]

![[Pasted image 20260902202633.png]]

## ==WHEN IS DESTRUCTOR CALL A MUST??==

![[Pasted image 20260902205647.png]]

## ==DIFFERENCE BETWEEN id = 0 AND this->id = 0 IN CONSTRUCTOR OR FUNCTION??==

Constructor ho ya koi bhi normal method, `id = 0;` likhne aur `this->id = 0;` likhne me **99% cases me compiler ke liye 0% difference** hota hai, par **1% case me code ka meaning completely badal jata hai**.

Dono situations ko step-by-step todte hain:

## 1. Case 1: Jab koi local variable ya parameter na ho (NO Name Clash)

Aapke pichhle code jaisa scenario:

![[Pasted image 20260902193438.png]]

### Yahan kya farak padega?

**Kuch bhi farak nahi padega — 100% same assembly code banta hai.**

- Jab aap bina `this->` ke sirf `id = 0;` likhte ho, toh compiler pehle function ke local scope me dhoondhta hai ki kya koi local variable ya parameter `id` naam ka hai?
    
- Jab usko koi local variable nahi milta, toh wo **implicitly (apne aap)** uske aage `this->` laga deta hai.
    
- Yaani aap `id = 0;` likho ya `this->id = 0;`, dono case me CPU ek hi instruction run karta hai: calling object ke base address par jakar `id` ko `0` set karna.
    

## 2. Case 2: Jab Parameter aur Class Member ka Naam SAME ho (Name Shadowing / Ambiguity)

Ye wo 1% case hai jahan `this->` likhna **mandatory (zaroori)** ho jata hai. Parameterized constructor ya setter functions me ye situation aati hai:

![[Pasted image 20260902193530.png]]

### `id = id;` me kya galti hui?

- C++ ka scoping rule kehta hai: **"Local variable hamesha class member ko chhipa (shadow) deta hai."**
    
- Jab compiler ne `id = id;` dekha, usne parameter wale `id` ko uthakar wapas parameter wale `id` me hi daal diya.
    
- Class ka jo actual `id` member tha, wo **uninitialized (garbage)** hi reh gaya!
    

### `this->` ne kaise bachaya?

![[Pasted image 20260902193706.png]]

Yahan `this->` ne compiler ko explicitly bataya: _"Bhai, left wala 'id' is object ki memory ka member hai, aur right wala 'id' bahar se aaya hua parameter hai."_

![[Pasted image 20260902194309.png]]

![[Pasted image 20260902194333.png]]

![[Pasted image 20260902194345.png]]

## 3. Difference Summary

|**Scenario**|**id = 0;**|**this->id = 0;**|
|---|---|---|
|**No Name Clash** (Parameter alag naam ka hai ya koi parameter nahi hai)|Perfectly fine. Compiler implicitly `this->` maan leta hai.|Perfectly fine. Explicit hai par extra typing hai.|
|**Name Clash** (Parameter/Local variable ka naam bhi `id` hai)|❌ **Bug!** Sirf local variable modify hoga, object ka data member uninitialized reh jayega.|✅ **Correct.** Disambiguate karta hai ki class member ko assign karna hai.|
|**Templates / Derived Classes** (Advanced C++)|Kuch template inheritance ke cases me dependent names resolve karne ke liye zaroori hota hai.|Direct member lookup trigger karta hai.|

## Clean Code Rule of Thumb:

1. Agar parameter aur member variable ka naam **same** hai $\rightarrow$ `this->id = id;` likho.
    
2. Agar parameter ka naam **alag** hai (jaise `Student(int studentId)`) $\rightarrow$ seedha `id = studentId;` likho (ya better: Initializer list use karo `Student(int id) : id(id) {}`).

## 3. The `this` Pointer (Under the Hood)

Interview me pucha jane wala classic sawaal: **"What is `this` pointer in C++?"**

- `this` ek **constant pointer (`Student* const this`)** hota hai jo current calling object ke memory address ko hold karta hai.
    
- Jab aap `s1.study()` call karte ho, compiler internally function ko aise pass karta hai:

![[Pasted image 20260901223221.png]]

- **Use Cases of `this`:**
    
    1. **Name Ambiguity Resolve Karna:** Jab parameter ka naam aur class member variable ka naam same ho (`this->name = name`).
        
    2. **Method Chaining:** Object ka reference return karna (`return *this;`).
        
![[Pasted image 20260902211851.png]]

![[Pasted image 20260902212314.png]]

## ==CAN WE DECLARE AND MAKE A CLASS INSIDE main FUNCTION??==

![[Pasted image 20260902212415.png]]

### Log Local Class normal coding me kyu use nahi karte?

1. **Scope Restriction:** Ye class sirf `main()` function ke andar exist karti hai. Isko `main()` ke bahar koi dusra function ya file use nahi kar sakti.
    
2. **Static Member Limitations:** C++ me local classes static member variables declare nahi kar saktin.
    
3. **Industry Standard:** Real projects (jaise Unreal Engine ya standard backends) me har class apni separate `.h` (header) aur `.cpp` (source) file me banti hai taaki pure project me reuse ho sake.

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
