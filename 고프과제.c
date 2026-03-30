#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 가위, 바위, 보를 문자열로 반환하는 도움 함수
const char* get_hand_name(int hand) {
    if (hand == 1) return "가위";
    if (hand == 2) return "바위";
    return "보";
}

int main() {
    int user_choice, ai_choice;
    int result; // 0: 비김, 1: 승리, 2: 패배
    
    // 난수 초기화 (매번 다른 결과를 위해 현재 시간 사용)
    srand(time(NULL));

    printf("가위바위보 토너먼트\n");
    printf("비길 경우 재경기\n\n");
    printf("[대진표 ]\n");
    printf("8강\n");
    printf("[1] 플레이어 VS [2] 철수\n");
    printf("[3] 영희     VS [4] 민준\n");
    printf("[5] 지아     VS [6] 현우\n");
    printf("[7] 수빈     VS [8] 태양\n\n");
    printf("당신은 [1] 플레이어입니다. [cite: 4, 10]\n");

    // --- 8강: 상대 철수 ---
    printf("\n8강 - 상대 : 철수 [cite: 5, 11]\n");
    while (1) {
        printf("1: 가위\n2: 바위\n3: 보\n");
        printf("선택 > ");
        
        // 예외 처리: 1, 2, 3 이외의 값 입력 시 재입력 
        if (scanf("%d", &user_choice) != 1 || user_choice < 1 || user_choice > 3) {
            printf("1, 2, 3 중에서 입력하세요 > ");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        ai_choice = rand() % 3 + 1; // 1~3 사이 난수 생성 
        printf("\n나: %s\n", get_hand_name(user_choice));
        printf("철수: %s\n", get_hand_name(ai_choice)); [cite: 6, 11]

        if (user_choice == ai_choice) {
            printf("=> 비겼습니다! 재경기!\n\n"); [cite: 6, 11]
            continue; 
        } else if ((user_choice == 1 && ai_choice == 3) || 
                   (user_choice == 2 && ai_choice == 1) || 
                   (user_choice == 3 && ai_choice == 2)) {
            printf("=> 이겼습니다!\n");
            break; // 8강 통과
        } else {
            printf("=> 졌습니다...\n아쉽습니다. 다음 기회에!\n"); [cite: 12, 14]
            return 0; // 프로그램 종료
        }
    }

    // --- 4강: 상대 민준 ---
    printf("\n4강 - 상대 : 민준 \n");
    while (1) {
        printf("1: 가위\n2: 바위\n3: 보\n선택 > ");
        scanf("%d", &user_choice);

        ai_choice = rand() % 3 + 1;
        printf("\n나: %s\n", get_hand_name(user_choice));
        printf("민준: %s\n", get_hand_name(ai_choice)); [cite: 8, 12]

        if (user_choice == ai_choice) {
            printf("=> 비겼습니다! 재경기!\n\n"); [cite: 8]
            continue;
        } else if ((user_choice == 1 && ai_choice == 3) || 
                   (user_choice == 2 && ai_choice == 1) || 
                   (user_choice == 3 && ai_choice == 2)) {
            printf("=> 이겼습니다! 결승 진출!\n"); [cite: 8, 12]
            break; 
        } else {
            printf("=> 졌습니다...\n아쉽습니다.\n"); [cite: 13]
            return 0;
        }
    }

    // --- 결승: 상대 태양 ---
    printf("\n결승 - 상대 : 태양 [cite: 9, 13]\n");
    while (1) {
        printf("1: 가위\n2: 바위\n3: 보\n선택 > ");
        scanf("%d", &user_choice);

        ai_choice = rand() % 3 + 1;
        printf("\n나: %s\n", get_hand_name(user_choice));
        printf("태양: %s\n", get_hand_name(ai_choice)); [cite: 9, 13]

        if (user_choice == ai_choice) {
            printf("=> 비겼습니다! 재경기!\n\n");
            continue;
        } else if ((user_choice == 1 && ai_choice == 3) || 
                   (user_choice == 2 && ai_choice == 1) || 
                   (user_choice == 3 && ai_choice == 2)) {
            printf("=> 이겼습니다!\n\n축하합니다! 우승!\n"); [cite: 9]
            break;
        } else {
            printf("=> 졌습니다...\n아쉽습니다. 다음 기회에!\n"); [cite: 13, 14]
            return 0;
        }
    }

    return 0;
}
