#include <stdio.h>

int main() {
    int level;
    printf("Enter level (1-4): ");
    scanf("%d", &level);

    if (level < 1) {
        printf("The level below 1 is not allowed\n");
    } else if (level > 4) {
        printf("The level above 4 is not allowed\n");
    } else {
        switch (level) {
            case 1:
                printf("Beginner\n");
                break;
            case 2:
                printf("Intermediate\n");
                break;
            case 3:
                printf("Advanced\n");
                break;
            case 4:
                printf("Expert\n");
                break;
        }
    }
    
    return 0;
}
//1. การวิเคราะห์โปรแกรมเดิม
//โปรแกรมนี้รับค่า level ที่เป็นตัวเลขเต็มจากผู้ใช้ จากนั้นใช้คำสั่ง switch เพื่อเปรียบเทียบค่า level กับกรณี (case) ต่างๆ และพิมพ์ข้อความที่เหมาะสมออกมา
//สิ่งที่ต้องสังเกตคือ:
//case 1 และ case 2 ไม่มี break: นี่คือจุดสำคัญที่จะทำให้เกิด "fall-through" หรือการทำงานต่อเนื่องไปสู่ case ถัดไป
// case 3 และ case 4 มี break: เมื่อโปรแกรมทำงานถึงบรรทัดนี้แล้วจะหลุดออกจากบล็อก switch ทันที
// default: จะทำงานเมื่อค่า level ไม่ตรงกับ case ใดๆ เลย
//2. การทดสอบและวิเคราะห์ผลลัพธ์
//เราจะทดสอบโปรแกรมด้วยค่า level ต่างๆ ตามโจทย์ และอธิบายผลลัพธ์ที่ได้
 // กรณี level = 0:
// ผลลัพธ์: Invalid level
// อภิปราย: ค่า level ไม่ตรงกับ case 1, 2, 3, หรือ 4 ดังนั้นโปรแกรมจึงเข้าสู่ default และแสดงข้อความ "Invalid level"
// กรณี level = 1:
// ผลลัพธ์: Beginner ตามด้วย Intermediate ตามด้วย Advanced ตามด้วย Expert ตามด้วย Invalid level
// อภิปราย:
// โปรแกรมเข้า case 1 พิมพ์ "Beginner"
// เนื่องจาก ไม่มี break โปรแกรมจึงทำงานต่อเนื่อง (fall-through) ไปยัง case 2 พิมพ์ "Intermediate"
// เนื่องจาก ไม่มี break โปรแกรมจึงทำงานต่อเนื่องไปถึง case 3 พิมพ์ "Advanced" แล้วเจอ break ทำให้หลุดออกจาก switch
// ผลที่คาดไม่ถึง: จริงๆ แล้ว จากโค้ดต้นฉบับ เมื่อใส่ 1 จะได้ผลลัพธ์คือ Beginner, Intermediate, Advanced และ Expert เพราะ case 3 ไม่มี break แต่ในรูปมี break ที่บรรทัด 11 ทำให้หยุดที่ Advanced
// อภิปรายใหม่:
//โปรแกรมเข้า case 1 พิมพ์ Beginner\n
// เนื่องจากไม่มี break โปรแกรมจึงทำงานต่อใน case 2 พิมพ์ Intermediate\n
// เนื่องจากไม่มี break โปรแกรมจึงทำงานต่อใน case 3 พิมพ์ Advanced\n
// เจอ break ที่บรรทัด 11 ทำให้โปรแกรมหยุดทำงานใน switch
// สรุปผลลัพธ์: Beginner ตามด้วย Intermediate ตามด้วย Advanced
// กรณี level = 2:
// ผลลัพธ์: Intermediate ตามด้วย Advanced
// อภิปราย:
// โปรแกรมเข้า case 2 พิมพ์ "Intermediate"
// เนื่องจากไม่มี break โปรแกรมจึงทำงานต่อใน case 3 พิมพ์ "Advanced"
// เจอ break ทำให้หลุดออกจาก switch
// กรณี level = 3:
// ผลลัพธ์: Advanced
// อภิปราย:
// โปรแกรมเข้า case 3 พิมพ์ "Advanced"
// เจอ break ทำให้หลุดออกจาก switch ทันที ไม่ทำงานใน case อื่นๆ
// กรณี level = 4:
// ผลลัพธ์: Expert
// อภิปราย:
// โปรแกรมเข้า case 4 พิมพ์ "Expert"
// เจอ break ทำให้หลุดออกจาก switch ทันที
// กรณี level = 10:
// ผลลัพธ์: Invalid level
// อภิปราย: ค่า level ไม่ตรงกับ case ใดๆ เลย ดังนั้นโปรแกรมจึงเข้าสู่ default และแสดงข้อความ "Invalid level"
//การอภิปรายผลลัพธ์ของโปรแกรมที่อัปเกรด
//เราจะทดสอบด้วยค่าต่างๆ อีกครั้งเพื่อดูความเปลี่ยนแปลง
// กรณี level = -4:
// ผลลัพธ์: The level below 1 is not allowed
// อภิปราย: โปรแกรมเข้าเงื่อนไข if (level < 1) และแสดงข้อความเตือนที่ชัดเจน
// กรณี level = 0:
// ผลลัพธ์: The level below 1 is not allowed
// อภิปราย: โปรแกรมเข้าเงื่อนไข if (level < 1) และแสดงข้อความเตือน
// กรณี level = 1:
// ผลลัพธ์: Beginner
// อภิปราย: ค่า level อยู่ในช่วงที่กำหนด (1-4) โปรแกรมจึงเข้าบล็อก else และทำงานใน switch ซึ่ง case 1 จะทำงานและพิมพ์ "Beginner" จากนั้น break จะหยุดการทำงานทันที
// กรณี level = 2:
// ผลลัพธ์: Intermediate
// อภิปราย: โปรแกรมเข้าบล็อก else และ switch ทำงาน case 2 พิมพ์ "Intermediate"
// กรณี level = 3:
// ผลลัพธ์: Advanced
// อภิปราย: โปรแกรมเข้าบล็อก else และ switch ทำงาน case 3 พิมพ์ "Advanced"
// กรณี level = 4:
// ผลลัพธ์: Expert
// อภิปราย: โปรแกรมเข้าบล็อก else และ switch ทำงาน case 4 พิมพ์ "Expert"
// กรณี level = 100:
// ผลลัพธ์: The level above 4 is not allowed
// อภิปราย: ค่า level เกิน 4 โปรแกรมจึงเข้าเงื่อนไข else if (level > 4) และแสดงข้อความเตือนที่ชัดเจน
// การปรับปรุงโปรแกรมนี้ทำให้การจัดการค่าที่ไม่ถูกต้องมีประสิทธิภาพและเป็นมิตรกับผู้ใช้มากขึ้น โดยแยกการตรวจสอบเงื่อนไขออกจากบล็อก switch อย่างชัดเจน และเพิ่ม break ในทุก case เพื่อป้องกันปัญหา fall-through ที่อาจทำให้เกิดผลลัพธ์ที่คาดไม่ถึงได้