import sys
print("자산 관리 프로그램, 관리자 : 홍길동, 20201111")

menu = []
i = 0

while(True):
    print("========================기능================")
    print(" 1. 음료추가 2.음료삭제 3.자판기이용 4.종료 ")
    print("============================================")
    

    number = int(input("기능선택: "))

    if number == 1:
        print("음료 목록: ", menu)
        insert_menu = input("추가할 음료는? ")
        menu.append(insert_menu)
        print("음료 목록:", menu)

    if number == 2:
        print("음료 목록: ", menu)
        remove_menu = input("삭제할 메뉴는? ")
        menu.remove(remove_menu)
        print("음료 목록: ", menu)

    if number == 3:
        coin = int(input("동전을 넣으세요(500원이상):"))
        print("(현재 금액: %d)" % coin, "음료 목록:", menu)

        while(True):
            select_menu = int(input("음료를 선택하세요(순서대로 1,2,3... 입력, 고스름돈 받기:0):"))
            if(select_menu == 0):
                print("거스름돈은", coin,"원 입니다")
                break
            else:
                print(menu[i - 1],"가 나왔습니다")
                coin = coin - 500
                print("(현재 금액: %d)" % coin, "음료 목록:", menu)
    if number == 4:
        print("자판기 관리 프로그램 종료")
        sys.exit()
                
        
        
        
        
    
