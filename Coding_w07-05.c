#include <stdio.h>

int main() {
    int age;
    int vipLevel;
    float purchaseAmount;
    float discountRate = 0.0; // กำหนดค่าเริ่มต้นของส่วนลดเป็น 0

    // ส่วนที่ 1: รับข้อมูลลูกค้า
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter VIP level (1-5): ");
    scanf("%d", &vipLevel);
    printf("Enter purchase amount: ");
    scanf("%f", &purchaseAmount);

    // ส่วนที่ 2: ตรวจสอบและคำนวณส่วนลดตามเงื่อนไข
    // เงื่อนไขแรก: ตรวจสอบส่วนลด 25% (VIP 5 หรือยอดซื้อสูง)
    if (vipLevel == 5 || purchaseAmount > 50000) {
        discountRate = 0.25;
    }
    // เงื่อนไขที่สอง: ตรวจสอบส่วนลด 20% (อายุ > 60 หรือ VIP 3-4)
    else if (age > 60 || vipLevel == 3 || vipLevel == 4) {
        discountRate = 0.20;
    }
    // เงื่อนไขที่สาม: ตรวจสอบส่วนลด 15% (อายุ 30-40 และยอดซื้อ > 2000)
    else if (age >= 30 && age <= 40 && purchaseAmount > 2000) {
        discountRate = 0.15;
    }
    // เงื่อนไขที่สี่: ตรวจสอบส่วนลด 10% (อายุ 18-25 และยอดซื้อ > 1000)
    else if (age >= 18 && age <= 25 && purchaseAmount > 1000) {
        discountRate = 0.10;
    }
    // กรณีสุดท้าย: ไม่เข้าเงื่อนไขใดเลย
    else {
        discountRate = 0.0;
    }

    // ส่วนที่ 3: แสดงผลลัพธ์
    printf("\n--- Customer Info ---\n");
    printf("Age: %d | VIP Level: %d | Amount: %.2f THB\n", age, vipLevel, purchaseAmount);

    if (discountRate > 0) {
        int discountPercentage = (int)(discountRate * 100);
        printf("Discount received: %d%%\n", discountPercentage);
    } else {
        printf("No discount applied\n");
    }

    printf("\nThank you for shopping with us!\n");

    return 0;
}
//คำอธิบายโ
//1. การรับข้อมูล (ส่วนที่ 1)
// #include <stdio.h>: เป็นการเรียกใช้ไลบรารีมาตรฐานสำหรับ Input/Output ในภาษา C
// int age;, int vipLevel;, float purchaseAmount;: ประกาศตัวแปรเพื่อเก็บข้อมูล อายุ (จำนวนเต็ม), ระดับ VIP (จำนวนเต็ม) และยอดซื้อ (ทศนิยม)
// float discountRate = 0.0;: ประกาศและกำหนดค่าเริ่มต้นให้ตัวแปรอัตราส่วนลดเป็น 0 เพื่อป้องกันความผิดพลาดและใช้เป็นค่าเริ่มต้นสำหรับกรณีที่ไม่ได้รับส่วนลด
// printf("Enter age: ");: แสดงข้อความแจ้งให้ผู้ใช้ทราบว่าต้องป้อนข้อมูลอะไร
// scanf("%d", &age);: อ่านค่าที่ผู้ใช้ป้อนจากคีย์บอร์ดและเก็บไว้ในตัวแปร age โดยใช้ %d สำหรับ integer
// scanf("%f", &purchaseAmount);: ใช้ %f เพื่อรับค่าทศนิยมสำหรับยอดซื้อ
//2. การตรวจสอบเงื่อนไข (ส่วนที่ 2)
// if (vipLevel == 5 || purchaseAmount > 50000): เงื่อนไขแรกสำหรับส่วนลด 25%
// ใช้ตัวดำเนินการ || (OR) หมายถึง ถ้า vipLevel เท่ากับ 5 หรือ purchaseAmount มากกว่า 50,000 ให้เงื่อนไขนี้เป็นจริง
// else if (age > 60 || vipLevel == 3 || vipLevel == 4): เงื่อนไขที่สองสำหรับส่วนลด 20%
// ใช้ตัวดำเนินการ || (OR) เพื่อตรวจสอบว่าลูกค้าเข้าเกณฑ์ใดเกณฑ์หนึ่งในสามเกณฑ์นี้หรือไม่
// else if (age >= 30 && age <= 40 && purchaseAmount > 2000): เงื่อนไขสำหรับส่วนลด 15%
// ใช้ตัวดำเนินการ && (AND) เพื่อตรวจสอบว่าลูกค้าต้องเข้าเกณฑ์ทั้งสามข้อพร้อมกันจึงจะได้รับส่วนลดนี้
// else if (age >= 18 && age <= 25 && purchaseAmount > 1000): เงื่อนไขสำหรับส่วนลด 10%
// ใช้ตัวดำเนินการ && (AND) เช่นกัน เพื่อตรวจสอบเงื่อนไขทั้งหมด
// else { ... }: ถ้าไม่เข้าเงื่อนไขใด ๆ เลย โปรแกรมจะทำคำสั่งในบล็อก else นี้ โดย discountRate จะยังคงเป็น 0.0 ตามที่กำหนดไว้แต่แรก
//3. การแสดงผลลัพธ์ (ส่วนที่ 3)
// printf("\n--- Customer Info ---\n");: แสดงข้อมูลลูกค้าในรูปแบบที่อ่านง่าย * printf("Age: %d | VIP Level: %d | Amount: %.2f THB\n", age, vipLevel, purchaseAmount);: แสดงข้อมูลที่รับมา
// %.2f ใช้เพื่อแสดงค่าทศนิยมของยอดซื้อเพียง 2 ตำแหน่ง
// if (discountRate > 0): ตรวจสอบว่ามีส่วนลดที่ได้รับหรือไม่
// int discountPercentage = (int)(discountRate * 100);: แปลงอัตราส่วนลดเป็นเปอร์เซ็นต์แบบจำนวนเต็มเพื่อให้แสดงผลได้ง่ายขึ้น (เช่น 0.20 * 100 = 20)
// printf("Discount received: %d%%\n", discountPercentage);: แสดงเปอร์เซ็นต์ส่วนลดที่คำนวณได้
// else { ... }: ถ้า discountRate เป็น 0 จะแสดงข้อความ No discount applied ตามโจทย์ที่ต้องการ
// printf("\nThank you for shopping with us!\n");: แสดงข้อความปิดท้าย
//โค้ดนี้ผ่านเกณฑ์การประเมินที่คุณให้มาทั้งหมด:
// การรับข้อมูลอย่างถูกต้อง: รับครบทั้ง 3 ตัวแปร
// โครงสร้าง if-else if-else: ใช้โครงสร้างที่ถูกต้องและเหมาะสม
// เงื่อนไขซับซ้อน: มีการใช้ && และ || ในเงื่อนไขอย่างถูกต้อง
// การคำนวณส่วนลด: คำนวณค่าส่วนลดได้ถูกต้องตามลำดับความสำคัญของเงื่อนไข
// การแสดงผลลัพธ์: แสดงข้อมูลลูกค้าและส่วนลดที่ได้รับ หรือแสดงข้อความ No discount applied ในกรณีที่ไม่มีส่วนลด