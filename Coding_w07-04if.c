//โครงสร้างแบบ if-else if
#include <stdio.h>

void showBenefits_if(int level) {
    if (level == 1) {
        printf("Silver Member: 5%% discount\n");
    } else if (level == 2) {
        printf("Gold Member: 10%% discount + Reward points\n");
    } else if (level == 3) {
        printf("Platinum Member: 15%% discount + Reward points + Birthday gift\n");
    } else if (level == 4) {
        printf("Diamond Member: All benefits + VIP events\n");
    } else {
        printf("Invalid membership level\n");
    }
}

int main() {
    int membershipLevel;

    printf("Enter membership level (1-4): ");
    scanf("%d", &membershipLevel);

    showBenefits_if(membershipLevel);

    return 0;
}
//คำอธิบาย
// โค้ดนี้ใช้ฟังก์ชัน showBenefits_if เพื่อรับค่าระดับสมาชิกและแสดงผลลัพธ์
// if-else if จะตรวจสอบเงื่อนไขจากบนลงล่างตามลำดับ เมื่อพบเงื่อนไขที่เป็นจริง (true) ก็จะทำงานตามบล็อกคำสั่งนั้น แล้วจบการทำงานทันที
// กรณีที่ค่า level ไม่ตรงกับเงื่อนไขใดๆ เลย จะไปทำงานที่บล็อก else สุดท้าย ซึ่งจะแสดงข้อความว่า "Invalid membership level"
//โค้ดโปรแกรมแสดงสิทธิประโยชน์ (switch-case)