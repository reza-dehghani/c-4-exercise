#include <stdio.h>

// تعریف تابع برای محاسبه میانه
float  calculatemiane(float *store_arr, int n);

int main() {
   //تعریف n و گرفتن از کاربر برای آرایه پویا
    // تعریف n و counter به ترتیب برای تعداد عناصر آرایه و شمارنده حلقه
    int n, counter;
    //تعریف number برای ذخیره موقت عدد گرفته شده از کاربر
    float *number;
    // گرفتن تعداد عناصر آرایه و ذخیره آن در n
    scanf ("%d",&n);
    //تعریف آرایه پویا
  number = malloc(n * sizeof *number); 
  //    float *store_arr = new float[n];
    // حلقه برای پیمایش و گرفتن اعداد از کاربر و ذخیره آن ها در آرایه
    for(counter= 0; counter<n ; counter++){
        int k;
        float *l;
        scanf ("%f",&number[counter]);
    }
    // چاپ میانه با استفاده از تابع
    printf("%f",calculatemiane(number, n));
    //حذف آرایه پویا
    free(number);
   return 0;
}

//پیاده سازی تابع محاسبه میانه
float calculatemiane(float *store_arr, int n){
    // اگر تعداد عناصر آرایه بیشتر از یکی بود
    if(n>1){
        // قرار دادن تعداد عناصر آرایه در متغیر count برای ارسال به آرایه مرتب سازی
    int count = n;
    // ارسال آرایه پویا و تعداد عناصر آن به تابع مرتب سازی
    int i, j;
    float temp;
    // پیمایش آرایه نامرتب
        for (i = 0; i < count; i++) 
        {
            for (j = i + 1; j < count; j++)
            {
                //درصورتی که عنصر قبلی از بعدی بزرگ تر است
                if (store_arr[i] > store_arr[j]) 
                {
                    // جابجایی عناصر به جای هم
                    temp =  store_arr[i];
                    store_arr[i] = store_arr[j];
                    store_arr[j] = temp;
                }
            }
        }
                    for (j = 0; j < count; ++j)
                    {
                        printf("%f",store_arr[j]);
                        printf("\n");
                    }
        //این شرط زوج بودن عناصر آرایه را محاسبه می کند
    if(n%2==0)
    {
        // فرمول محاسبه میانه برای اعداد زوج به صورت جمع دو عدد وسط / ۲
        float one = store_arr[(n/2)-1], two =  store_arr[(n/2)];
        // چاپ میانه اعداد زوج و return تابع و ارسال خروجی به تابع
        return (one+two)/2;
    }
    //شرط فرد بودن تعداد عناصر آرایه
    else if (n%2!=0)
        {
            // ارسال مقدار وسط آرایه به خروجی آرایه
        return store_arr[n/2];
    }
    }
    //در صورتی که آرایه فقط یک عنصر داشت نیازی به محاسبه عنصر وسط نیست و میانه برابر خود عدد است
    else{
        return store_arr[0];
    }
}

