# 컴퓨터의 실수 표현

10진수 실수를 2진수로 표현 할 때 소수점을 기준으로 정수 부분은 표현하는 법이 같으며 소수 부분의 표현운 2의 음수 지수의 형태로 표현됩니다. 소수 부분의 자리 공간에 따른 값과 소수점을 기준으로 공간의 값은 아래 표와 같습니다.

![binary_num](https://github.com/geunkim/CPPLectures/raw/master/BasicProgramming/images/binary_num.png)

![binary_dec_map](https://blog.kakaocdn.net/dn/elgM3R/btq2CYAxXxR/SJgSDFH68yn0JT3WBMffQ1/img.png)

예로 10진수 0.625를 2진수로 표기하면 0.101 = 1 * 0.5 + 0 * 0.25 + 0 * 0.125입니다.

만약 10진수 0.4를 2진수로 표기하면 0.00110011...의 형태로 (0011)이 무한 반복됩니다. 즉 비트의 수가 유한한 2진수로 표현하지 못하는 수가 존재하기 때문에 컴퓨터에는 표현할 수 있는 가장 근사치 값이 저장됩니다. 근사 값을 저장하는 방법으론 두가지가 있으며 각각 고정소수점과 부동소수점입니다.


# 고정소수점(Fixed Point)

고정소수점이란 정수 부분을 표현하는 비트 수와 소수를 표현하는 비트 수를 사전에 정한 후 해당 비트 수만을 이용하여 수를 표현하는 방식입니다.
만약 정수를 표현하는 비트를 증가시키면 큰 수를 표현할 수 있으나 정밀한 수를 표현하는 것이 어려워지고, 소수를 표현하는 비트 수를 늘리면 정밀한 수를 표현할 수 있으나 큰 수를 표현할 수 없습니다.

![Fixed Point](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F998D03435C920B7718)

맨 앞 1자리는 부호 비트(Sign bit)라고 해서 0이면 양수, 1이면 음수라는 뜻입니다.

나머지 비트들은 소수점을 기준으로 정수부와 소수부를 표현하는 비트로 각각 나누게 되는데, 소수점의 위치는 미리 정해둔다. 소수부의 경우 앞에서부터 채우며 남는 뒷자리는 다 0으로 채워집니다.

구현하기 편리하지만 사용하는 비트 수 대비 표현 가능한 수의 범위 또는 정밀도가 낮기 때문에 실수를 다룰 필요가 있는 범용 시스템에서는 거의 안쓰이고, 높은 정밀도가 필요 없는 소규모 시스템에서는 간혹 쓰입니다.


# 부동소수점(Floating-point)

부동소수점이란 단어에서 부동은 소수점이 떠다닌다는 의미로 자료형 처리에 있어 소수점 위치가 바뀐다는 것이며, 영어로는 Floating-point format 입니다.
단정도와 배정도라는 말로 자료형을 구분하는데, 단정도 부동소수점 자료형은 32bit float이며 배정도 부동소수점 자료형은 64bit double을 말합니다.

수치해석용 프로그램들은 대부분 자체 자료형을 갖고 있고 숫자를 문자열 구조로 만들어 계산하여 수치 자료형의 한계를 극복합니다.

부동소수점 자료형 처리는 고정소수점 자료형 처리에 비해 복잡한 연산이 필요하므로 컴퓨터 하드웨어의 성능을 표현할 때 부동소수점 처리 능력이 빠지지 않습니다.

## IEEE 754 부동소수점 표현

![Floating-point](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F99B8704C5C920A0728)

IEEE(미국의 전기 전자 기술자 협회)에서 개발한 컴퓨터에서 부동소수점을 표현하는 가장 널리 쓰이는 표준으로서 부동소수점 방식이 32비트 기준 위의 그림과 같은 구조를 가집니다.

부호비트는 고정소수점과 같으며 지수의 부호를 뜻하는게 아니라 전체 숫자의 부호를 뜻하는 것입니다.

23자리 가수부는 정규화 결과 소수점 오른쪽에 있는 숫자들을 왼쪽부터 그대로 넣으면 된다. 남는 자리는 0으로 채워집니다.

지수부에는 IEEE 표준에 따라 지수를 그대로 넣는게 아닌 bias라고 하는 지정된 숫자를 더한 다음 넣어야 합니다. 32비트를 쓰는 경우 bias는 127이라고 규정하고 있습니다.
지수부에 별개의 음수 표현을 하지 않도록 하기 위해 10진수 기준으로 1 ~ 127구간은 음수, 128~254 구간은 양수를 표현하도록 만들고 편향 값인 127을 더하게 됐습니다.

지수값 2^2=4 즉 10이기 때문에 2 + 127 = 129를 2진수로 바꾼 10000001이 들어가 위와 같은 그림의 지수가 들어가있습니다.

bias라는 값을 사용하는 이유는 지수가 음수가 될 수 있기 때문에 그렇습니다. 만약 0.000101이라는 이진수가 있다면 정규화에 대해서 설명할 때 정수부를 1로 만들어야합니다. 그러니 오른쪽으로 소수점을 밀어서 1.01*2^-4가 됩니다.

정규화라는 것은 2진수를 1.xxxx... *2^n꼴로 변환하는 것을 말합니다. 정수부에 1만 남을때까지 소수점을 왼쪽(정수부가 0일 경우엔 오른쪽)으로 이동시키고, 이동한 칸 수 만큼 n자리에 집어넣으면 됩니다.

double은 1~2045까지의 지수 표현이 가능하고 2048개의 지수 표현이 가능합니다.

각각 데이터 타입에서 0과 마지막 수는 표현 가능한 범위를 넘어서는 값을 표현하기 위해서 빠지게 되었습니다. 표현은 아래와 같습니다.

### Denormalized Number [지수부 0, 가수부 0이 아닌 수]

해당 경우는 표현할 수 있는 가장 작은 지수보다도 더 작은 경우를 의미합니다.

float의 경우 지수부에 편향 값을 취하기 전 float에서 표현할 수 있는 가장 작은 지수 값은 -127입니다. 이 때 2<sup>-127</sup>보다 더 작은 수를 의미합니다.

### Infinity [지수부 2<sup>e</sup> - 1, 가수부 0]

실수를 표현할 때, 부호 비트를 사용할 수 있는 덕분에 음의 무한과 양의 무한을 표현할 수 있게 됐습니다.

### NaN [지수부 2<sup>e</sup> - 1, 가수부 0이 아닌 수]
+∞−∞, −∞+∞, 0×∞, 0÷0, ∞÷∞처럼 값을 엄밀하게 정할 수 없는 것들을 의미합니다.

# 컴퓨터의 문자 표현

문자도 컴퓨터에 저장되는 경우 2진수를 사용합니다. 문자는 영문 알파벳뿐 아니라 한글 등 각국의 문자가 저장되어야 하므로 각 문자를 구분하기위한 방법을 고려해야합니다. 다양한 문자를 표현하기 위해 각 문자별로 2진수의 코드 값을 부여한 코드 체계를 이용하며, 코드체계로는 아스키코드(ASCII: American Standard Code ofr information Interchange Code)와 유니코드(Unicode) 등이 있습니다.

# 아스키코드 (ASCII Code)

아스키코드는 7bit 부호체계(3개의 zone bit, 4개의 digit bit)로 구성되어 000(0x00)부터 127(0x7F)까지 총 128개의 부호가 사용되어 33개의 출력 불가능한 제어 문자와 공백을 비록한 95개의 출력 가능한 문자 128개의 문자를 표현하기 위해 개발됐습니다. 3개의 zone bit는 영문자, 숫자, 특수문자를 구분하는 데 사용하며, 제어문자들은 이제 대부분 사용되지 않고 있으며 출력 가능한 문자는 52개의 대소문자 알파벳과 10개의 숫자, 1개의 공백문자, 32개의 특수문자로 구성됩니다.

7비트만 사용하는 이유는 나머지 1비트를 통신 에러 검출을 위해 사용했기 때문입니다. Parity Bit라고 해서, 7개의 비트 중 1의 개수가 홀수면 1, 짝수면 0로 하는 식의 패리티 비트를 붙여서 전송 도중 신호가 변질된 것을 수신측에서 검출해낼 확률을 높인 것입니다. 현재는 쓰이지 않으며 맨 앞 비트에 0을 붙이고 이어서 7비트가 사용되는 식의 인코딩이 일반적입니다.

![ASCII_CODE](https://github.com/geunkim/CPPLectures/raw/master/BasicProgramming/images/ASCII_CODE.png)

아스키 코드에 의하면 대문자 'A'는 10진수로 65이고 저장곤간에는 2진수로 01000001가 저장됩니다.

## ANSI 코드

각 나라의 문자를 표현하기 위한 방법으로 표준화된 것으로 각 나라의 확장된 부분의 이름을 따서 EUC-KR, EUC-JP라 부릅니다. 

ASCII 코드를 확장하여 8bit로 구성되었으며 앞의 7bit는 ASCII와 동일하고 뒤 1bit는 다른 언어의 문자를 표현합니다.

새로 추가된 128개 문자로는 모든 언어의 문자를 표현할 수 없어서 생긴 개념이 CodePage 입니다. 각 언어별로 Code 값을 주고, Code마다 다른 문자열 표를 의미하도록 약속 했습니다. 

# 유니코드(UniCode)

전 세계의 모든 문자를 컴퓨터에서 일관되게 표현할 수 있는 표준 문자 코드표로 컴퓨터간 문자 데이터 교환을 원활하게 하기 위해 유니코드 협회가 제정하였습니다.

문자를 표현하기 위해서 16bit를 할당하여 65,536개의 문자를 표현할 수 있는 문자 집합으로 아스키코드를 포함합니다. 아스키코드를 유니코드로 표현할 때는 0000 0000을 붙입니다. 아스키코드는 U+0000 ~ U+007F 영역에 매핑됩니다. 각 문자 집합을 영역 또는 블록이라 하고 각 영역 또는 블록 내의 각 문자는 코드 포인트(Code Point)가 매핑되며 한 코드 영역은 다른 코드 영역과 겹치지 않으며 영역의 크기는 16의 배수이고 각 영역은 16의 배수(U+nnnn)의 코드 포인트로 시작됩니다.

기본 다국어 평면(BPM, Basic Multilingual Plane)을 포함하여 16개의 평면으로 구성되면 기본 다국어 평면은 65,536개의 코드 포인터를 가지고 있으며 한글도 이 평면에 매핑됩니다. 한글은 U+AC00 ~ U+D7AF 영역에 매핑됩니다.

유니코드의 인코딩 방식으로 UTF(Universal Transformation Format)-8, UTF-16 UTF-32 등이 있습니다.

## UTF-8

UTF-8 코딩 방식은 가변길이 문자 인코딩방식(멀티바이트) 이며, ANSI의 단점을 보완하기 위해 만들어졌습니다. ANSI는 다국어를 지원하기 위해 CodePage 정보를 미리 알고 있어야 하지만, UTF-8은 멀티바이트 개념을 사용해 하나의 Character Set에 거의 모든 문자를 넣었습니다.

멀티바이트란 표현해야하는 문자에 따라 글자 크기를 가변으로 변경하여 사용하는 것을 말합니다. ANSI는 고정바이트(1byte) 형태로 최대 256자까지만 표현이 가능하나 UTF-8은(1~4byte)1,112,064자까지 표현이 가능합니다.

첫 128자는 기존 ASCII 코드 값으로 ANSI와 동일합니다. 그래서 영어를 사용할 경우 1byte만 사용합니다.

2byte는 중동지역, 많은 유럽 언어가 사용하며, 3byte이상은 한국, 중국, 일본 등 동아시아권 언어가 사용합니다.

## UTF-16

문자가 2byte씩 할당되는 UTF-8의 변형이라고 보면 되는데,  한글의 경우 UTF-8로 저장할 경우 3byte가 필요하지만 16에선 2byte면 돼 용량의 이점이 있습니다. 그러나 경우에 따라 2byte 이상을 사용할 경우가 있어 용량의 이점이 크다보기 어렵고, 엔디안 처리를 고려함에 따른 복잡성 증대와 ANSI와 호환이 안되는 단점이 있습니다.

## UTF-32

모든 문자를 4byte로 고정하는 인코딩을합니다.

유니코드 코드 포인트가 직접 인덱싱 된다는 장점을 가지고 있는데 일련의 코드 포인트에서 N번째 코드를 찾은 것은 상수 시간 작업이지만 가변 길이 코드(UTF-8,UTF-16가 해당)는 문자열 시작부터 N 코드 포인트를 계산하기 위해 선형 시간이 필요해 상대적으로 처리과정이 간단하며, 빠른 속도를 가집니다.

단점으로는 UTF-16의 두 배에 가까워 매우 비효율적인 메모리를 사용하므로 많은 저장 공간을 사용해 자주 사용되지 않습니다.