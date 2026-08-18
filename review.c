#include <stdio.h>
#include <stdlib.h>


/*
=========================================================
1. FUNCTION + POINTER
=========================================================

این تابع آدرس یک int را می‌گیرد.

int *p
یعنی:
p یک pointer است که به یک int اشاره می‌کند.

*p
یعنی:
مقدار موجود در آدرسی که p به آن اشاره می‌کند.
*/

void changeValue(int *p)
{
    *p = 100;
}


/*
=========================================================
2. POINTER TO POINTER + MALLOC
=========================================================

int **p
یعنی:
p یک pointer است که به یک pointer دیگر اشاره می‌کند.

ما از این روش استفاده می‌کنیم تا تابع بتواند
خود pointer اصلی را تغییر دهد.
*/

void createArray(int **p, int size)
{
    /*
    malloc حافظه‌ای برای size عدد int می‌گیرد.

    اگر int = 4 bytes باشد و size = 5:

    5 * 4 = 20 bytes
    */

    *p = malloc(size * sizeof(int));


    /*
    بررسی می‌کنیم malloc موفق شده یا نه.

    چون *p خود pointer اصلی است،
    باید خود آن را با NULL مقایسه کنیم.
    */

    if (*p == NULL)
    {
        return;
    }


    /*
    پر کردن آرایه

    (*p)[i]

    یعنی:
    pointer اصلی → عنصر i

    معادل مفهومی:

    *((*p) + i)
    */

    for (int i = 0; i < size; i++)
    {
        (*p)[i] = (i + 1) * 10;
    }
}


/*
=========================================================
3. FUNCTION FOR PRINTING ARRAY
=========================================================

const int *numbers

یعنی تابع اجازه دارد آرایه را بخواند،
ولی اجازه تغییر عناصر را ندارد.

size تعداد عناصر آرایه است.
*/

void printArray(const int *numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}


int main()
{
    /*
    =====================================================
    4. NORMAL VARIABLE
    =====================================================
    */

    int x = 10;

    printf("x = %d\n", x);


    /*
    =====================================================
    5. ADDRESS OPERATOR &
    =====================================================

    &x یعنی:
    آدرس x را بده.
    */

    printf("address of x = %p\n", (void *)&x);


    /*
    =====================================================
    6. POINTER
    =====================================================
    */

    int *p = &x;

    /*
    p
    یعنی آدرس x

    *p
    یعنی مقدار x
    */

    printf("p = %p\n", (void *)p);
    printf("*p = %d\n", *p);


    /*
    =====================================================
    7. تغییر مقدار از طریق POINTER
    =====================================================
    */

    *p = 20;

    printf("x after *p = 20: %d\n", x);


    /*
    =====================================================
    8. POINTER ARITHMETIC
    =====================================================

    یک آرایه معمولی:

    numbers:
    [10][20][30][40]

    numbers + 1
    به عنصر بعدی می‌رود.

    *(numbers + 1)
    مقدار عنصر بعدی را می‌دهد.
    */

    int numbers[] = {10, 20, 30, 40};

    printf("first = %d\n", *numbers);
    printf("second = %d\n", *(numbers + 1));
    printf("third = %d\n", *(numbers + 2));


    /*
    =====================================================
    9. ARRAY INDEXING
    =====================================================

    numbers[i]

    تقریباً معادل:

    *(numbers + i)
    */

    printf("numbers[2] = %d\n", numbers[2]);
    printf("*(numbers + 2) = %d\n", *(numbers + 2));


    /*
    =====================================================
    10. CONST POINTER / CONST DATA
    =====================================================
    */

    const int fixed = 50;

    /*
    این pointer اجازه تغییر fixed را ندارد.
    */

    const int *constPointer = &fixed;

    printf("const value = %d\n", *constPointer);


    /*
    این مجاز است:

    constPointer = &x;

    چون خود pointer ثابت نیست.

    اما این مجاز نیست:

    *constPointer = 100;

    چون داده const است.
    */


    /*
    =====================================================
    11. POINTER TO POINTER
    =====================================================
    */

    int value = 30;

    int *ptr = &value;

    int **pp = &ptr;


    /*
    ساختار:

    pp
    ↓
    ptr
    ↓
    value
    ↓
    30
    */

    printf("value = %d\n", value);
    printf("*ptr = %d\n", *ptr);
    printf("**pp = %d\n", **pp);


    /*
    تغییر value از طریق pointer به pointer
    */

    **pp = 40;

    printf("value after **pp = 40: %d\n", value);


    /*
    =====================================================
    12. MALLOC
    =====================================================

    malloc حافظه را در زمان اجرای برنامه
    به صورت Dynamic اختصاص می‌دهد.
    */

    int *dynamicNumber = malloc(sizeof(int));


    /*
    همیشه نتیجه malloc را بررسی کن.
    */

    if (dynamicNumber == NULL)
    {
        printf("malloc failed!\n");
        return 1;
    }


    /*
    مقداردهی حافظه Heap
    */

    *dynamicNumber = 500;

    printf("dynamic number = %d\n", *dynamicNumber);


    /*
    =====================================================
    13. FREE
    =====================================================

    حافظه‌ای که malloc کرده‌ایم
    باید در نهایت آزاد شود.
    */

    free(dynamicNumber);

    /*
    بعد از free بهتر است pointer را NULL کنیم.
    */

    dynamicNumber = NULL;


    /*
    =====================================================
    14. DYNAMIC ARRAY
    =====================================================
    */

    int size = 5;

    int *dynamicArray = malloc(size * sizeof(int));

    if (dynamicArray == NULL)
    {
        printf("malloc failed!\n");
        return 1;
    }


    /*
    پر کردن آرایه Dynamic
    */

    for (int i = 0; i < size; i++)
    {
        dynamicArray[i] = (i + 1) * 100;
    }


    /*
    چاپ آرایه
    */

    printf("dynamic array:\n");

    printArray(dynamicArray, size);


    /*
    =====================================================
    15. REALLOC
    =====================================================

    حالا می‌خواهیم آرایه را از 5 عنصر
    به 8 عنصر افزایش دهیم.
    */

    int newSize = 8;


    /*
    بهتر است realloc را مستقیماً داخل
    dynamicArray نریزیم.

    اول یک pointer موقت می‌گیریم.
    */

    int *temp = realloc(
        dynamicArray,
        newSize * sizeof(int)
    );


    /*
    بررسی موفقیت realloc
    */

    if (temp == NULL)
    {
        printf("realloc failed!\n");

        /*
        حافظه قبلی هنوز معتبر است،
        پس آن را آزاد می‌کنیم.
        */

        free(dynamicArray);

        return 1;
    }


    /*
    realloc موفق شده.

    حالا pointer اصلی را به آدرس جدید
    منتقل می‌کنیم.
    */

    dynamicArray = temp;


    /*
    عناصر جدید را مقداردهی می‌کنیم.

    عناصر 0 تا 4 قبلاً وجود داشتند.

    پس از عنصر 5 شروع می‌کنیم.
    */

    for (int i = size; i < newSize; i++)
    {
        dynamicArray[i] = (i + 1) * 100;
    }


    printf("array after realloc:\n");

    printArray(dynamicArray, newSize);


    /*
    =====================================================
    16. استفاده از FUNCTION برای تغییر مقدار
    =====================================================
    */

    int number = 10;

    printf("before changeValue: %d\n", number);

    changeValue(&number);

    /*
    چون آدرس number را فرستادیم:

    &number
       ↓
    p
       ↓
    number

    پس تابع می‌تواند مقدار number را تغییر دهد.
    */

    printf("after changeValue: %d\n", number);


    /*
    =====================================================
    17. CREATE ARRAY WITH int **
    =====================================================
    */

    int *createdArray = NULL;

    /*
    &createdArray یعنی:

    آدرس خود pointer را به تابع بده.
    */

    createArray(&createdArray, 5);


    if (createdArray == NULL)
    {
        printf("createArray failed!\n");

        free(dynamicArray);

        return 1;
    }


    printf("array created by function:\n");

    printArray(createdArray, 5);


    /*
    =====================================================
    18. FREE ALL DYNAMIC MEMORY
    =====================================================
    */

    free(dynamicArray);
    dynamicArray = NULL;

    free(createdArray);
    createdArray = NULL;


    return 0;
}