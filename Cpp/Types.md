# 자료형(Data Type)

특정 목적에 맞는 자료를 저장하기 위해 만든 형식(format, layout)을 말하며 프로그래머가 자료(data)를 사용하려는 의도를 컴파일러나 인터프리터에게 알려주는 자료의 속성이다.

# 자료형의 분류

자료형은 크게 두가지로 구분한다. 하나는 프로그래밍 언어가 제공하는 기본 자료형(char, int , double, ...) 다른 하나는 개발자가 필요에 의해 만드는 사용자 정의 자료형이다.사용자 정의 자료형은 기본 자료형 외 class, struct, union 등으로 만든 모든 것이다.

C++에서는 일반적으로 기본 자료형으로 정의한 것을 변수, 사용자 정의 자료형으로 정의한 것을 객체라고 한다 하지만 객체는 변수를 포함하므로 일반적인 설명을 위해 객체라는 용어를 더 많이 사용한다.

# 기본 자료형

하드웨어의 자원(resources)이 유한하기 때문에 프로그래밍 언어에서 사용하는 자료형으로 표현 가능한 수치 또한 유한하다.

## 기본 자료형의 종류는 다음과 같다.
<table>
    <tr>
        <td>데이터 형태(자료형)</td>
        <td>자료형</td>
        <td>설명</td>
        <td>메모리 공간</td>
        <td>범위</td>
    </tr>
    <tr>
        <td>문자형(정수형)</td>
        <td>char (character)</td>
        <td>문자 및 정수</td>
        <td>1바이트</td>
        <td>-128 ~ 127</td>
    </tr>
    <tr>
        <td rowspan="4">정수형</td>
        <td>short</td>
        <td>정수값 저장</td>
        <td>2바이트</td>
        <td>-32768 ~ 32767</td>
    </tr>
    <tr>
        <td>int (integer)</td>
        <td>정수값 저장</td>
        <td>4바이트</td>
        <td>-214783648 ~ 214783647</td>
    </tr>
    <tr>
        <td>long</td>
        <td>정수값 저장</td>
        <td>8바이트</td>
        <td>-9223372036854775808 ~ 9223372036854775807</td>
    </tr>
    <tr>
        <td>long long</td>
        <td>정수값 저장</td>
        <td>8바이트</td>
        <td>-9223372036854775808 ~ 9223372036854775807</td>
    </tr>
    <tr>
        <td rowspan="3">실수형</td>
        <td>float</td>
        <td>단일 정밀도 부동소수점</td>
        <td>4바이트</td>
        <td>1.17549e-38 ~ 3.40282e+38</td>
    <tr>
        <td>double</td>
        <td rowspan="2">두배 정밀도 부동 소수점</td>
        <td>8바이트</td>
        <td>2.22507e-308 ~ 1.79769e+308</td>
    </tr>
    <tr>
        <td>long double</td>
        <td>16바이트</td>
        <td>3.3621e-4932 ~ 1.18973e+4932</td>
    </tr>
    <tr>
        <td>불형</td>
        <td>bool (boolean)</td>
        <td>참/거짓 표현</td>
        <td>1바이트</td>
        <td>true,false</td>
</table>

## int
int는 32, 64bit 시스템 상관없이 4byte이다.

## long
32bit 시스템에서는 4byte지만 64bit 시스템에서 long은 8byte 정수 자료형이다.