## 1. The Core Intuition: "OOPS is Life"

Procedural programming (C style ya pure functions) me **Data** alag ghumta hai aur **Logic/Functions** alag. Real world me aisa nahi hota:

- Real world me entities hoti hain (Car, Person, Student, Enemy, Weapon).
    
- Har entity ke paas do cheezein hoti hain:
    
    1. **State / Attributes (Data):** Object kaisa dikhta hai ya uski properties kya hain (e.g., Car ka color, Student ka roll number, Player ki Health).
        
    2. **Behavior / Methods (Functions):** Object kya kaam karta hai (e.g., Car drive hoti hai, Student study karta hai, Player attack karta hai).
        

OOPs ka core idea yahi hai: **Data aur uske upar act karne wale Functions ko ek single unit (Container/Capsule) me bind karna.**

## 2. Problem with Procedural / Functional Approach

Video me ek case study samjhai gayi: Agar 100 ya 10,000 Students ka data manage karna ho bina OOPs ke:

![[Pasted image 20260830190556.png]]

### Major Limitations jo samne aati hain:

### A. Code Messiness & Synchronization Risk

Index mismatch ka massive risk rehta hai. Agar `names[2]` ke saath galti se `ages[3]` pass ho gaya, toh data corrupt ho jayega. Data logically binded nahi hai.

### B. Scalability & Extensibility Nightmare (The Signature Change Problem)

Agar kal ko ek nayi property add karni ho (jaise `gpa` ya `partnerName`):

- Aapko har jagah naya variable banana padega.
    
- Har existing function (e.g., `study()`, `sleep()`, `bunk()`) ka **function signature change** karna padega.

![[Pasted image 20260830190631.png]]

- Bade codebase (e.g., AAA Game engine ya Enterprise backend) me agar 500 functions hain, toh 500 jagah changes propagate karne padenge.

### C. Uncontrolled Global State & No Access Boundaries

Procedural style me functions ke beech data share karne ke liye log aksar **Global Variables** bana dete hain:

- Problem: Global data ko koi bhi irrelevant function access ya modify kar sakta hai bina permission ke.
    
- Jaise video me bataya: Agar `schoolName` ek global variable hai, toh `study()` ke saath-saath koi `flying()` ya `teaching()` function bhi usko bina control ke alter kar sakta hai.
    
- Isse **Side Effects** aur **Heisenbugs** (aise bugs jo track nahi hote) create hote hain.
    

## 3. The OOPs Solution: Class & Object Foundation

![[Pasted image 20260830190842.png]]

- **Class:** Blueprint / Custom Data Type jo memory tab tak nahi leta jab tak object na bane (conceptual schema).
    
- **Object:** Us blueprint ka memory instance jisme actual data store hota hai.
    

## DIFFERENCE BETWEEN BLUEPRINT, OBJECT AND INSTANCE??

## Blueprint vs Object vs Instance

- **Blueprint (Class / Design Map):**
    
    - Jaise ek building banane se pehle architect ek **naksha (blueprint)** banata hai.
        
    - Us nakshe par koi reh nahi sakta, usme cement ya bricks nahi lagti. Wo sirf ek instruction sheet hai jo batata hai ki kitne rooms honge aur doors kahan lagenge.
        
    - C++ me `class` wahi blueprint hai. **Ye RAM me koi variable data space occupy nahi karta** (sirf type metadata define karta hai).
        
- **Object / Instance (Physical Realization):**
    
    - Us nakshe ko dekhkar jab zameen par actual building khadi kar di jati hai, wo **Object / Instance** hai.
        
    - **Instance** ka simple matlab: Blueprint ka ek concrete example jo **RAM me physical memory occupy karta hai**.
![[Pasted image 20260830202510.png]]

## WHAT ARE THE PROGRAMMING PARADIGMS??

| **Paradigm**                                 | **Core Idea**                                                                                                 | **Main Focus**                     | **Limitation**                                                                            |
| -------------------------------------------- | ------------------------------------------------------------------------------------------------------------- | ---------------------------------- | ----------------------------------------------------------------------------------------- |
| **Procedural (e.g., C)**                     | Step-by-step instructions and procedures (`main` calls `funcA` calls `funcB`).                                | Functions and execution flow.      | Data global ghumta hai, secure nahi hota. Code tightly coupled ho jata hai.               |
| **Functional (e.g., Haskell, Lisp)**         | Pure mathematical functions. No mutable state (variables change nahi hote, input lo $\rightarrow$ output do). | Functions as first-class citizens. | Game states, inventory, real-time mutable systems track karna complex ho jata hai.        |
| **Modular (e.g., Modula-2, C with headers)** | Code ko alag-alag files/modules me divide karna.                                                              | File separation.                   | Logic separate hoti hai par direct data-behavior encapsulation aur inheritance nahi hota. |
| **OOPs (e.g., C++, Java, C#)**               | Real-world simulation. Data + Behavior packaged in single units (Objects).                                    | Entities and their interactions.   | Procedural se slight setup overhead, par massive scalable architectures banti hain.       |

## DIFFERENCE BETWEEN struct AND class??

### C ke `struct` me kya kami thi?

C language me `struct` sirf **Passive Data Container** hota tha. Uske andar functions nahi daal sakte the:

![[Pasted image 20260830202726.png]]

### Problem in C:

1. **No Access Control (Zero Security):** C struct ka har member completely `public` hota hai. Koi bhi external function `p.health = -9999;` kar sakta tha bina validation ke.
    
2. **No Data-Function Binding:** Function alag file me hai, data alag file me.
    

### C++ ne kya kiya?

C++ me `struct` aur `class` dono ko functions aur access modifiers allow kar diye.

![[Pasted image 20260830202754.png]]

## WHY OOPS BETTER??

![[Pasted image 20260830202856.png]]

## WHAT IS DIFFERENCE BETWEEN global, public, private AND protected??

![[Pasted image 20260830203040.png]]

### Summary of Access Modifiers

- **`private` (Default in Class):** High security. Internal variables jo galat modify hone par crash karwa sakte hain (e.g., Player `health`, `balance`, pointers).
    
- **`public`:** External Interface. Buttons aur methods jo bahar ki duniya ke use ke liye banaye gaye hain (e.g., `deposit()`, `attack()`, `render()`).
    
- **`protected`:** Inheritance gateway. Child classes use karengi, par `main()` ke liye `private` rahega.
    
- **`global`:** Sabke liye open, par enterprise/game code me avoid kiya jata hai kyunki ye state corruption ka sabse bada source hai.

## EXACT DIFFERENCE BETWEEN global AND public??

## Global vs Public me Difference Kya Hai?

Dono me zameen-aasman ka fark hai:

- **Scope vs Access Modifier:**
    
    - `global` ek **Lifetime/Scope** concept hai (Variable kahan exist karta hai).
        
    - `public` ek **Access Specifier** concept hai (Kaun use kar sakta hai).
        
- **Entity Context:**
    
    - **Global Variable:** Kisi object se juda nahi hota. Pure software me ek hi copy hoti hai jo Data Segment me rehti hai.
        
    - **Public Member:** Object ke andar rehta hai. Har object ki apni alag copy hoti hai.

![[Pasted image 20260830203244.png]]

## HOW OBJECT'S SIZE IS CALCULATED AND MEMORY MANAGEMENT IS DONE??

## 1. Object Ka Size Kaise Calculate Hota Hai?

Object ka total size uske andar ke **non-static data members** ke size ka sum hota hai (along with compiler padding).

### Example: Variables ka Size

![[Pasted image 20260830203443.png]]

### Behind the Scenes: Memory Padding & Alignment

Compiler CPU cache performance ke liye variables ko 4-byte ya 8-byte boundaries par align karta hai:

- `Player` class me: `int` (4) + padding (4) + `double` (8) + `char` (1) + padding (7) = **24 bytes**.
    
- `Student` class me: `int` (4) + padding (4) + `std::string` (32 bytes MSVC / 24 bytes GCC) = **32 to 40 bytes**.
    

### Important Interview Corner Cases:

1. **Functions size nahi lete:** Class ke functions (methods) object ke andar store nahi hote. Wo memory ke **Code Segment** me ek hi baar rehte hain. 1000 objects banaoge toh bhi function memory repeat nahi hogi.
    
2. **Empty Class Size = 1 Byte:** Agar class me kuch bhi nahi hai (`class Empty {};`), toh `sizeof(Empty)` **1 byte** hota hai taaki har object ko unique memory address mil sake.
    

## 2. Kya Objects Sirf Stack Me Bante Hain? (Stack vs Heap)

Bilkul nahi. Object kahan banega, ye is baat par depend karta hai ki aapne usko kaise allocate kiya hai:

![[Pasted image 20260830203523.png]]

|**Feature**|**Stack Allocation**|**Heap Allocation**|
|---|---|---|
|**Syntax**|`Student s1;`|`Student* s1 = new Student();`|
|**Speed**|Super fast (Stack pointer move hota hai)|Slower (OS se memory request karni padti hai)|
|**Lifetime**|Scope based (`{}` ke bahar nikalte hi khatam)|Manual (Jab tak `delete` na karo, tab tak RAM me rahega)|
|**Game Dev Usage**|Temporary calculations, local loop variables|Spawning enemies, loading world maps, asset loading|

## DOES public, private AND protected MAKE CHANGESIN THE SIZE OF OBJECT??

### 1. Kya `private`, `public` ya `protected` se Object ke Size par koi farak padta hai?

**Short Answer: Bilkul Nahi.**

Access modifiers (`private`, `public`, `protected`) sirf **Compiler ke security rules (gatekeepers)** hain.

- Ye rules sirf **Compile-Time** par check hote hain taaki developer galti se unauthorized member access na kar le.
    
- Jab code machine level / assembly me convert ho jata hai, tab binary ke andar `private` ya `public` ka koi tag nahi hota.
    
- `private int a;` aur `public int a;` dono memory me exact **4 bytes** hi lenge aur object ka layout bilkul same rahega.

## 2. Kya Class ko khud `private` ya `public` banaya ja sakta hai?

- **C++ me:** Top-level class ko `private` ya `public` nahi banate. C++ me top-level classes normal hoti hain (ya namespaces me hoti hain). Haan, agar **Nested Class** (ek class ke andar dusri class) banayein, toh inner class ko `private` ya `public` kar sakte hain:
![[Pasted image 20260830204932.png]]


## 4. Game Development & Performance Perspective (Extra Industry Insight)

Game Dev (jaise Unreal Engine ya custom C++ engines) me OOPs kaise model hota hai:

### Entity-Component vs Classical OOP

Game me har entity ek Object hoti hai:

![[Pasted image 20260830190910.png]]

- **Readability & Modular Isolation:** Har character apni health aur animation state khud manage karta hai. Combat system ko player ke private internal physics calculations janne ki zaroorat nahi hoti.
    
- **Game Dev Interview Tip (Data Locality):** Classical OOPs objects ko heap/stack me scatter karta hai. Modern game development me OOPs ko **Data-Oriented Design (DOD / ECS)** ke saath mix kiya jata hai taaki CPU Cache misses avoid ho sakein, par high-level gameplay orchestration hamesha OOPs classes/objects par rely karta hai.
    

## 5. MAANG & Tech Interview Key Takeaways

1. **Why OOPs over Procedural?**
    
    - _Modularity:_ Code isolated blocks me divide hota hai.
        
    - _Extensibility:_ Naya data/behavior add karne ke liye pure system ke function signatures break nahi hote.
        
    - _Maintainability (DRY Principle):_ Code duplicate nahi hota.
        
    - _Security & Abstraction:_ Internal details hide rehti hain, unauthorized access block hota hai.
        
2. **What is an Object fundamentally in Memory?**
    
    - Object memory me ek contiguous block of memory hota hai jo apne non-static data members ko store karta hai (functions code segment me rehte hain, har object ke andar repeat nahi hote).

