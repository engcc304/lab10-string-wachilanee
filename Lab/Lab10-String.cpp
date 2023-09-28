/*
    จงเขียนโปรแกรมเพื่อรับคำจากผู้ใช้งาน เพื่อตรวจสอบว่า คำที่กรอกมามีลักษณะเป็นคำหรือวลีที่สามารถอ่านจากหลังไปหน้าหรือหน้าไปหลังแล้วยังคงความหมายเหมือนเดิมได้
    โดยที่ หากคำนั้นสามารถอ่านจากหน้าไปหลังหรือหลังไปได้ ให้แสดงผลลัพธ์ว่า Pass แต่หากทำไม่ได้ให้ขึ้นว่า Not Pass

    Test case:
        Enter word:
            radar
    Output:
        Pass.

    Test case:
        Enter word:
            hello
    Output:
        Not Pass.

    Test case:
        Enter word:
            Radar
    Output:
        Pass.

    Test case:
        Enter word:
            here
    Output:
        Not Pass.
*/

#include <stdio.h>
#include <string.h>

// เช็คว่าเป็นพาลาไหม 
int is_palindrome(char *word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char user_input[100];
    printf("Enter word: ");
    scanf("%s", user_input);

    if (is_palindrome(user_input)) {
        printf("Pass.\n");
    } else {
        // ตรวจสอบว่าคำนั้นสามารถอ่านจากหน้าไปหลังหรือหลังไปหน้าได้
        int front_to_back = 1;
        int back_to_front = 1;

        int length = strlen(user_input);
        for (int i = 0; i < length / 2; i++) {
            if (user_input[i] != user_input[length - i - 1]) {
                front_to_back = 0;
                break;
            }
        }

        for (int i = 0; i < length; i++) {
            if (user_input[i] != user_input[length - i - 1]) {
                back_to_front = 0;
                break;
            }
        }

        if (front_to_back || back_to_front) {
            printf("Pass.\n");
        } else {
            printf("Not Pass.\n");
        }
    }

    return 0;
}
