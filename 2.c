#include <stdio.h>
#include <string.h>

int main(){
    // تعریف ساختمان student چون در سوال گفته شده است حدف انتساب ساختمان هاست
    // نام و شماره دانشجویی ورشته و معدل
    struct Student{
    char   name[30];
    int   studentnum;
    char   field[15];
    float    score;
};
//برای پیمایش
int n;
// برای ذخیره بزرگترین معدل
float max;
//ساخت آرایه ای از ساختمان داده struct با ۵ عنصر 
    struct Student st[5];
        printf("Lotfan etelaat danshjooyan ra vered konid:\n");

//با یک حلقه تک تک خانه های آرایه را از کاربر می گیریم  در واقع هر خانه شامل ۵ خانه داخل آن است که با یک نقطه به آن دسترسی داریم
    for(int i =0; i<5;i++)
{
        printf(" name: ");
        scanf("%s",&st[i].name);
            printf("student number: ");
        scanf("%s" ,&st[i].studentnum);
            printf("Field: ");
        scanf("%s",&st[i].field);
            printf("Score: ");
        scanf("%f",&st[i].score);
           fflush(stdin);
}
//برای پیمایش
    int i, j, min;
    // متغیر موقت برای پیدا کردن معدل
    float temp;
    // پیمایش آرایه نامرتب
        for (i = 0; i < 5; ++i) 
        {
            for (j = i + 1; j < 5; ++j)
            {
                //درصورتی که عنصر قبلی از بعدی بزرگ تر است
                if (st[i].score > st[j].score) 
                {
                    // جابجایی عناصر به جای هم
                    temp =  st[i].score;
                    st[i].score = st[j].score;
                    st[j].score = temp;
                }
            }
        }
        //عنصر قبل از آخرین عنصر شماره ۴ چون آرایه از صفر شروع می شود می شود خانه سوم
        printf("%f", st[3].score);
    return 0;
}
