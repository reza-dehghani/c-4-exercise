// در این برنامه نام و آدرس دانشجویان در قالب یک لیست پیوندی گرفته و ذخیره شده است؛ یک نام و آدرس به عنوان نمونه در لیست
// وجود دارد و برای اینکه برنامه بسته نشود غیرقابل حذف است چرا که اگر قسمت head لیست پیوندی حذف شود دیگر لیست وجود ندارد
#include <stdio.h>
 #include <string.h>
#include <stdlib.h>

// تعریف لیست پیوندی حاوی نام و آدرس
 typedef struct Node {
    char name[20];
    char town[10];
    char street[10];
    int plaque;
    int index;
  struct Node * next;
}node_t; // نام لیست
 
int main(){
    
    //تعریف قسمت head
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    
    //قرار دادن یک نمونه در لیست به صورت پیشفرض
    strcpy(head->name, "ali");
    strcpy(head->town, "tehran");
    strcpy(head->street,"jomhori");
    head->plaque = 0;
    
    //ثابت ها برای کنترل اجرای برنامه و شمارنده
    double exit=1;
    int counter = 0;
    int select, edame =0 ;

//حلقه اصلی برای انتخاب گزینه های مختلف
// شرط خروج صفر شدن متغیر exit
while(exit!=0){
    
    //پاک کردن صفحه برای کاربری راحت تر
    system("cls"); //pak kardan safhe windows
    system("clear"); //pak kardan safhe linux
    
    //منوی برنامه و متغیر برای انتخاب گزینه مورد نظر
    printf("Lotfan entekhab konid\n1-azafe\n2-print list\n3-hazf\n4-exit\n");
    scanf("%d",&select);
    
    //گزینه اول اضافه کردن به لیست
    if(select == 1){
    // متغیر اولیه برای مقدار دهی موقت
    char name0[20], town0[10], street0[10];
    int plaque0, index;
    // نمایش متغیر های برای ورود اطلاعات توسط کاربر
    printf("INDEX: for delete ");
    printf("%d",counter);
      printf("\nName: ");
  scanf(" %s", name0);
    printf("\nTown: ");
  scanf(" %s", town0);
    printf("\nStreet: ");
  scanf(" %s", street0);
    printf("\nPlaque: ");
  scanf(" %d", &plaque0);
  
  //تعریف متغیر current به عنوان متغیر اصلی و قرار دادن هد لیست در آن
    node_t * current = head;
    // تا زمانی که خانه بعدی لیست نال نیست برو خانه بعدی و مقدار current را یکی ببر جلو
    while (current->next != NULL) {
        current = current->next;
    }
    // حافظه پویا برای مقدار نکست متغیر current
    current->next = (node_t *) malloc(sizeof(node_t));
    // انتساب متغیر های موقت و قرار دادن در لیست
    strcpy(current->next->name, name0);
    strcpy(current->next->town, town0);
    strcpy(current->next->street, street0);
    current->next->plaque = plaque0;
    current->next->index = counter;
    // خانه بعدی را نال قرار بده تا مشخص شود که انتهای لیست کجاست
    current->next->next = NULL;
    //شمارنده برای تعداد آیتم های لیست
    counter++;
    // کنترل اجرای برنامه
    printf("\baray edame kelid 1 ra feshar dahid?\n");
    scanf("%d",&edame);
    if(edame == 1)
        continue;
        else
     continue;
}
if(select == 2){
    // گزینه ۲ چاپ لیست استفاده از current برای چاپ مثل قبل با این تفاوت که در اینجا متغیر را چاپ می کند
    node_t * current = head;
    // انتهای حلقه کارنت را یکی جلو می بریم پس تا وقتی که به انتها نرسیدی ادامه بده
    while (current != NULL) {
        // اطلاعات را یکی یکی با اشاره گر دریافت و چاپ کن
        printf("\nName: ");
        printf("%s", current->name);
                printf("\nTown: ");
        printf("%s", current->town);
                printf("\nStreet: ");
        printf("%s", current->street);
                printf("\nPlaque: ");
        printf("%d", current->plaque);
                        printf("\n");
        current = current->next;
    }
        // کنترل اجرای برنامه
    printf("\baray edame kelid 1 ra feshar dahid?\n");
    scanf("%d",&edame);
    if(edame == 1)
        continue;
        else
     continue;
}
if(select == 3){
    //متغیر اس برای قرار دادن مقداری که میخواهیم جستجو کنیم
    int s;
    
    printf("INDEX fardi ke mikhahid hazf konid ra vared konid: (start from -1)");
    scanf("%d",&s);
    // برای پیمایش حلقه
    int i = 0;
    // لیست های موقتی برای حذف نودی که جستجو می کنیم دو تا خالی هستند و یکی مثل قبل متغیر current
    node_t *current = head;
    node_t * temp_node = NULL;
    node_t * next_node = NULL;
    //اگر لیست خالی بود خطا بده
    if (head == NULL) {
        printf("khata list khali ast");
    }
    //اگر لیست فقط یک نود یا گره داشت
        if(s==-1)
        {      
            //لیست را خالی کن
        free(head); //دستور پاک کردن حافظه پویا
        //مشابه قسمت اول قرار دادن مقدادیر خالی در اولین آیتم لیست
    strcpy(head->name, "empty");
    strcpy(head->town, "empty");
    strcpy(head->street,"empty");
    head->plaque = 0;  
        continue; // برو اول حلقه
        }
        // اگر مقداری که میخواهیم جستجو کنیم بزرگتر از تعداد اعضای لیست بود خطا بده
    if(s>counter)
    {
        printf("khata meghdar vorodi bozorgtar ast");
        break;// از حلقه خارج شو
    }
    // تا زمانیکه به شماره مورد نظر گره نرسیدی کارنت را ببر جلو
    for( i =0 ; i<s; i++){
        current = current->next;
    }
    // مقدار گره بعدی کارنت را برای پاک نشدن داخل تمپ می ریزیم تا بعد بتوانیم کارنت را ببریم جلو
            temp_node = current->next;
            // حال کارنت را یکی به جلو می بریم
            current->next = temp_node->next;
            // حافظه پویای تمپ را خالی می کنیم در واقع همان لیست تمپ ابتدا
            free(temp_node);
            // پیغام موفقیت آمیز بودن حذف
            printf("\nFard mored nazar hazf shod\n");
    // کنترل اجرای برنامه
    printf("baray edame kelid 1 ra feshar dahid?\n");
    scanf("%d",&edame);
    if(edame == 1)
        continue;
        else
     continue;
}
//برای خروج از برنامه
if(select == 4){
        exit = 0;
    }
}
}

