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
    
## Structure Padding aur Alignment (Kyu laya gaya aur kaise kaam karta hai?)

### Ye concept kyu laya gaya? (The Hardware Reason)

Modern CPUs (32-bit / 64-bit) RAM se data **1 byte karke nahi padhte**.

- 64-bit CPU ek cycle me **8 bytes (1 Word)** ek saath read karta hai.
    
- CPU hamesha **Word-Aligned addresses** (addresses jo 4 ya 8 ke multiples hote hain: `0x00`, `0x04`, `0x08`, `0x10`) se data fast read kar sakta hai.
    

Agar ek 4-byte `int` kisi aise address par aa gaya jo 4 ka multiple nahi hai (jaise `0x01` se `0x04`), toh CPU ko us `int` ko padhne ke liye **2 memory cycles** lagane padenge aur bit-shifting karni padegi (isko **Unaligned Memory Access** kehte hain, jisse performance drop hoti hai).

### Padding Kaise Kaam Karti Hai?

Rule: **Har data member apne size ke multiple wale offset address par hi store hoga.**

Dekhte hain C++ compiler is structure ko kaise arrange karta hai:

![[Pasted image 20260831225910.png]]

|**Offset Address**|**Member / Padding**|**Size**|**Kyu hua?**|
|---|---|---|---|
|`0x00`|`char a`|1 byte|Byte 0 par store hua|
|`0x01 - 0x03`|**[PADDING]**|**3 bytes**|Agle `int b` ko address `0x04` (4 ka multiple) par lane ke liye|
|`0x04 - 0x07`|`int b`|4 bytes|Aligned 4 bytes|
|`0x08`|`char c`|1 byte|Byte 8 par store hua|
|`0x09 - 0x0B`|**[PADDING]**|**3 bytes**|Pure object ka total size largest member (4 bytes) ka multiple hona chahiye|

- **Raw Total:** 1 + 4 + 1 = 6 bytes
    
- **Actual `sizeof(Example)`:** **12 bytes** (6 bytes data + 6 bytes empty padding).
    

### Pro-Dev / Game-Dev Optimization Tip:

Agar data members ko **decreasing order of size** (bade se chota) arrange kar dein:

![[Pasted image 20260831225948.png]]

**Optimized `sizeof(OptimizedExample)` = 8 bytes!** (4 bytes memory bacha li bina functionality badle). Game development me jab 100,000 objects spawn hote hain, ye alignment hazaron MBs RAM bacha leti hai.

### HOW THIS OPTIMISATION WORKS??

### 1. `char a` ke baad 3 bytes padding kyu nahi aayi?

Compiler ka ek golden rule hota hai: **"Data member sirf apne size ke multiple wale offset address par hi baith sakta hai."**

- `char` ka size = **1 byte**.
    
- 1 ka multiple har ek number hota hai ($0, 1, 2, 3, 4, 5, \dots$).
    
- Iska matlab `char` kisi bhi byte offset par bina kisi alignment constraint ke baith sakta hai.
    

Ab dekhte hain `OptimizedExample` me memory kaise bharti hai:

![[Pasted image 20260831230101.png]]

- **Step 1 (`int b`):** Size = 4 bytes. Ye offset `0x00` par baitha aur `0x00, 0x01, 0x02, 0x03` occupy kar liya. Next available address hai **`0x04`**.
    
- **Step 2 (`char a`):** Size = 1 byte. Isko 1 ka multiple chahiye. Agla available address **`0x04`** hai, jo 1 ka multiple hai. Toh ye seedha `0x04` par baith gaya. Next available address hai **`0x05`**.
    
- **Step 3 (`char c`):** Size = 1 byte. Isko bhi 1 ka multiple chahiye. Agla available address **`0x05`** hai, jo 1 ka multiple hai. Toh ye bina kisi padding ke seedha `0x05` par baith gaya. Next available address hai **`0x06`**.
    

#### Phir last me 2 bytes padding kyu aayi?

Compiler ka dusra rule: **"Puri class ka total size uske andar ke sabse bade primitive data member ke size ka multiple hona chahiye."**

- Class ka sabse bada member: `int b` (4 bytes).
    
- Abhi tak occupied memory: offset `0x00` se `0x05` = **6 bytes**.
    
- 6 kya 4 ka multiple hai? Nahi ($4 \times 1 = 4$, $4 \times 2 = 8$).
    
- Agla multiple **8** hai. Isliye compiler ne end me **2 bytes padding** (`0x06, 0x07`) daal di taaki jab aap is class ka array banao (e.g., `OptimizedExample arr[2]`), toh agla object theek 4-byte boundary (`0x08`) se start ho sake.
    

Total Size = **8 bytes**.

### 2. Hum 4 bytes choose karein ya 8 bytes?

Ye aapko manually "choose" nahi karna hota — ye do cheezon par automatically tay hota hai:

#### A. Target System Architecture (32-bit vs 64-bit)

- **32-bit CPU:** Bus width 4 bytes (32 bits) hoti hai. Pointer ka size **4 bytes** hota hai.
    
- **64-bit CPU (Modern PCs, PS5, Xbox, Servers):** Bus width 8 bytes (64 bits) hoti hai. Pointer ka size **8 bytes** hota hai.
    

#### B. Class ka Largest Member (Rule of Thumb)

Aapko alignment decide karte waqt bas ye dekhna hai ki aapki class ke andar **sabse bada data type** kaun sa hai:

|**Data Type**|**Typical Size (64-bit C++)**|**Alignment Requirement**|
|---|---|---|
|`char`, `bool`|1 byte|Any address (1-byte boundary)|
|`short`|2 bytes|2-byte boundary ($0, 2, 4, 6, 8, \dots$)|
|`int`, `float`|4 bytes|4-byte boundary ($0, 4, 8, 12, 16, \dots$)|
|`double`, `long long`, **Pointers (`int*`, `Player*`)**|8 bytes|8-byte boundary ($0, 8, 16, 24, 32, \dots$)|

![[Pasted image 20260831230550.png]]
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

## DOES public, private AND protected MAKE CHANGES IN THE SIZE OF OBJECT??

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

## HOW main() FUNCTION IS NECESSARY FOR C, C++ TYPE LANGUAGES AND NOT IN PYTHON, JS??

## `main()` Function: C/C++ vs Python/JS (CPU kaise execute karta hai?)

### C / C++ / Java (Compiled & Structured Entry Point)

1. C/C++ me compiler code ko machine code (ELF / PE binary) me convert karta hai.
    
2. Operating System ka **Loader/Kernel** binary ke header me dekhta hai ki **Entry Point** kahan hai (jo C runtime `_start` se hoke `main()` ko call karta hai).
    
3. CPU ko ek explicit address milta hai jahan se pehli instruction fetch karni hoti hai.
    

### Python aur JavaScript me bina `main()` ke kaise chalta hai?

CPU Python ya JS ke code ko directly execute **nahi karta**. CPU execute karta hai **Interpreter / Runtime Engine** ko:

- **Python:** CPU run karta hai `python.exe` (CPython interpreter binary jo C me likhi hai). CPython ke andar apna ek C ka `main()` hota hai. Wo aapki `.py` script ko upar se neeche line-by-line read karta hai, Bytecode banata hai, aur execute karta hai.
    
- **JavaScript:** CPU run karta hai **V8 Engine / Node.js runtime** (ye bhi C++ me likha hai). Is engine ka apna C++ `main()` hota hai, jo JS script ko parse karke JIT (Just-In-Time) compiler ke through machine code banata hai.
    

> **Summary:** CPU hamesha ek compiled binary ka `main()` hi run karta hai — C++ me wo aapka `main()` hota hai, Python/JS me wo **Interpreter/VM ka `main()`** hota hai jo aapki script ko evaluate karta hai.

![[Pasted image 20260831230754.png]]