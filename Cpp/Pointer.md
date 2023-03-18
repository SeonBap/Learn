# 포인터(Pointers)

정의된 자료형의 메모리 주소를 저장하는 변수입니다.

포인터 자료형은 메모리 주소를 저장하는 구조의 독립된 자료형입니다. 포인터 자료형으로 정의한 변수가 포인터 변수이고 일반적으로는 포인터라고 합니다. `DataType* pData;`에서 `DataType*`는 포인터 자료형(type of pointer)이고 `pData`는 포인터(variable of pointer)입니다. `pData`는 DataType으로 만들어진 자료가 저장되어 있는 메모리 주소를 저장하고, 연산자(*, ->, --, ++, +, -, [] 등)를 사용할 수 있습니다.

포인터라는 단어 사용이 포인터 자료형과 포인터 변수, 두 가지를 명확하게 구분하지 않고 중복된 의미로 사용하는 경우가 많습니다.

# 메모리(Memory)

운영시스템(OS, operationg system) 기반하에 실행되는 모든 프로그램은 프로세스 단위로 관리 되고 가상 메모리(virtual memory)를 사용합니다. OS가 각 프로그램에 동일한 가상 주소 공간(virtual address space)을 제공하고 관리는 OS가 합니다. 할당해주는 메모리 공간은 대표적으로 코드(Code), 데이터(Data), 스택(Stack), 힙(Heap)의 네 영역으로 구성됩니다.

1. 코드(code) \
실행할 프로그램의 코드가 저장되는 영역으로 텍스트영역이라고도 부릅니다. CPU는 코드 영역에 저장된 명령어를 하나씩 가져가서 처리하게 됩니다.
2. 데이터(Data) \
메모리의 데이터(data) 영역은 프로그램의 전역 변수와 정적(static) 변수가 저장되는 영역입니다. \
프로그램의 시작과 함께 할당되며, 프로그램이 종료되면 소멸합니다.
3. 스택(stack) \
함수의 호출과 관계되는 지역 변수와 매갭녀수가 저장되는 영역입니다. \
함수의 호출과 함께 할당되며, 함수의 호출이 완료되면 소멸합니다. \
스택 영역에 저장되는 함수의 호출 정보를 스택 프레임(stack frame)이라고 합니다. \
푸시(push) 동작으로 데이터를 저장하고, 팝(pop) 동작으로 데이터를 인출합니다. 이러한 스택은 후입선출(LIFO, Last-In First-Out)방식에 따라 동작하므로, 가장 늦게 저장된 데이터가 가장 먼저 인출됩니다. \
메모리의 높은 주소에서 낮은 주소의 방향으로 할당됩니다.
4. 힙(heap) \
사용자에 의해 메모리 공간이 동적으로 할당되고 해제됩니다. \
메모리의 낮은 주소에서 높은 주소의 방향으로 할당됩니다.

컴퓨터 하드웨어를 구성하는 RAM(Random Access Memory)이 여기서 이야기하는 메모리에 해당하는 것으로 컴퓨터에서 여러 애플리케이션을 수행하는데 필요합니다. \
메모리에서 저장공간(위치)을 구별하기 위해 주소(address)라는 용어가 사용됩니다. 일반적인 집 주소, 메일 주소 같은 개념으로 메모리의 주소는 메모리의 저장 장소를 구별하는데 사용됩니다. \
컴퓨터 메모리의 구별은 바이트 단위로 이루어지며, 저장되는 데이터는 한 바이트마다 서로 다른 주소 값을 가집니다.

# 주소(adress)

데이터의 주소값이란 해당 데이터가 저장된 메모리의 시작 주소를 의미합니다. C++ 에서는 이러한 주소값을 1바이트 크기의 메모리 공간으로 나눠 이해할 수 있습니다. \
예를 들어, int형 데이터는 4바이트의 크기를 가지지만 int형 데이터의 주소값은 시작 주소 1바이트만을 가리키게 됩니다.

<img src= https://user-images.githubusercontent.com/112116885/226130007-2a68a6fd-ca9b-408c-93d4-4baff81b17ae.png width="50%" height="50%" title="주소" alt="주소"></img>