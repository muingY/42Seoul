## 0. Reference 모음

- basic shell : https://brennan.io/2015/01/16/write-a-shell-in-c/
- pipe(|) and semi colon(;) structure first: https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/2069210
- exam_rank_04: https://github.com/stevenkim18/Exam_Rank_04
- bash shell script book: https://mug896.github.io/bash-shell/index.html
- 미니쉘 velog: https://velog.io/@hidaehyunlee/minishell-1.-과제소개-및-선행지식
- evaluation pdf: https://github.com/rizky/42-corrections/blob/master/minishell.pdf

- miniShell 허용 함수 정리 (블로그 이전글에 pdf 해석도 존재): https://42kchoi.tistory.com/259?category=953120

- shell 의 명령어 해석 처리 순서: https://dbsc.tistory.com/34

- shell 명령: http://attiadmin.guyweb.co.kr/linux/shell.html


## 1. subject 관련

### 1.1 새로 추가된 external functions의 용도 파악



| Function | Desc                                                      | Synopsis                                       |
| :------- | --------------------------------------------------------- | ---------------------------------------------- |
| isatty   | test whether a file descriptor refers to a terminal       | int isatty(int fd);                            |
| ttyname  | return name of a terminal                                 | char *ttyname(int fd);                         |
| ttyslot  | find the slot of the current user's terminal in some file | int ttyslot(void);                             |
| ioctl    | control device                                            | int ioctl(int fd, unsigned long request, ...); |



| Function  | Desc                                                         | Synopsis                                                     |
| :-------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| getenv    | get an environment variable                                  | char *getenv(const char *name);                              |
| tcsetattr | set the parameters associated with the terminal              | int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p); |
| tcgetattr | get the parameters associated with the terminal              | int tcgetattr(int fildes, struct termios *termios_p);        |
| tgetent   | loads the entry for *name*. It returns 1 on success, 0 if there is no such entry, and -1 if the terminfo database could not be found. The emulation ignores the buffer pointer *bp*. | int tgetent(char \*bp, const char \*name);                   |
| tgetflag  | gets the boolean entry for *id*, or zero if it is not available | int tgetflag(char \*id);                                     |
| tgetnum   | gets the numeric entry for *id*, or -1 if it is not available | int tgetnum(char \*id);                                      |
| tgetstr   | returns the string entry for *id*, or zero if it is not available. Use **tputs** to output the returned string. The return value will also be copied to the buffer pointed to by *area*, and the *area* value will be updated to point past the null ending this value. | char \*tgetstr(char \*id, char \**area);                     |
| tgoto     | instantiates the parameters into the given capability. The output from this routine is to be passed to **tputs**. | char \*tgoto(const char \*cap, int col, int row);            |
| tputs     | is described on the **curs_terminfo**(3X) manual page. It can retrieve capabilities by either termcap or terminfo name. | int tputs(const char \*str, int affcnt, int (\*putc)(int));  |



## 2. 구현해야 할 내용들



### 절대경로 명령 실행

현재는 임시적으로 execvp() 사용중, 명령 실행시 사용해야하는 [execve() 함수는 env의 PATH를 참조하지 않기 때문에](https://stackoverflow.com/questions/14290556/running-executables-present-in-the-path-environment-using-execve), PATH의 각 요소를 이용해서 /로 시작하는 명령을 작성하고 하나 하나 try 해보거나 해당 명령의 절대경로를 찾은 다음에 절대경로로 실행

### pipe 처리

pipe
  https://nroses-taek.tistory.com/139
  https://github.com/LambdaSchool/CS-Wiki/wiki/How-Unix-Pipes-are-Implemented
dup, dup2
  https://reakwon.tistory.com/104

### termios

https://42born2code.slack.com/archives/CU6MU5TB7/p1618529655015900

https://www.gnu.org/software/libc/manual/html_node/Noncanon-Example.html

''미니쉘에서 인풋 프로세스 시작 시 논캐노니컬 설정-> 인풋 다 받으면 설정 되돌리기
요것만 해주면 미니쉘 안에서 미니쉘 실행하는 경우도 걱정 안하셔도 될 듯 합니다''

https://42born2code.slack.com/archives/CN9RHKQHW/p1615467571016000

"Hello everybody after investigation it seems impossible to finish minishell with only termcaps as it is required for us to read inputs directly.
And it seems that this can only be achieved through the use of termios's tcsetattr or the lower-level ioctl.
The fact that it just came into the mandatory part of the project may explain the reason why such necessity is not yet mentioned.

you can use :
isatty, ttyname, ttyslot ◦ ioctl ◦ getenv ◦ tcsetattr, tcgetattr ◦ tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs, signal"

https://www.gnu.org/software/libc/manual/html_node/Noncanon-Example.html

https://tldp.org/HOWTO/Serial-Programming-HOWTO/x115.html

https://42born2code.slack.com/archives/CU6MU5TB7/p1619504611007000

"미니쉘에서 언캐노니컬모드에서 커서를 받다가 언더플로우가 났다고 합니다
언더플로우가 날만한 곳이 없는데 왜 이런게 떴을까요?"

### env 관련

- 기존에는 char *ft_get_env(const char *key) 구현했어야 했던 것 같은데 지금은 getenv 사용할 수 있을까?


### $? 처리

https://42born2code.slack.com/archives/CU6MU5TB7/p1619082490369400

"구조체안에 status라는 변수를 넣어서 명령어의 종료상태(status)를 이 변수에 저장해두었습니다. 그런다음 echo $? 라는 명령어가 입력되면 파싱단계에서 $?를 status의 값으로 대체해주었고 결론적으로 echo 0 이렇게 되어, 0이 터미널에 출려되게끔 했습니다. 그리고 배쉬에서 테스트 해보시면, ls -al | grep test | asdasdasd 라는 명령을 치고 echo $? 하면 127이 나오고 asdaasd | asdasdasd | ls -al 을 치고 echo $?를 하면 0이 나옵니다. 파이프명령어의 제일 마지막에 오는 명령어의 상태값이 저장되는거 같더라구요"



## 3. 협업 미팅



### 01, 4월 19일 월요일 오후 5시 첫미팅 :기본적인 사항 공유

1. git repo: http://13.125.198.2:3000/hyungyyo/minishell.git
2. 디렉토리 구조
3. pipe, semicolon 을 처리하는 기본 구조
4. builtin 함수들
5. non-builtin 함수들 execve()로 구동하기 (99. env 참고)
6. redirect 처리
7. sinal 처리
8. 등등



### 02, 4월 21일 수요일 오전 10시 기본 코드관련 미팅

#### lsh + ft_split2 + gnl + t_builtin + norm (+ cmd | ; 구분 테스트 정도)

- 전역변수 builtin_str, builtin_func 부분 main의 지역변수로 처리하여 norm 코드 생성, 그 후에 두 변수들 t_builtin로 처리하였고 다시 g_tag 전역변수 구조체의 멤버로 처리하여 사용중
- libft랑 gnl이랑 겹치는 함수들이 있었는데 libft 함수를 쓰면 문제가 생겨서 gnl_utils 함수들은 func2로 rename해서 사용
- execution 실행되는 상태 + norm



### 03, 4월 23일 금요일 오전 10시

- pipe, semicolon과 quotatin mark, double quotation mark 연동
- char \*\*env를 char \*\*envp로 변경, t_env *env 생성
- builtin 함수들
  - cd.c, env.c 연결
  - 입력인자들 변경: t_tag *tag, t_cmd *cmd, t_env *env



### 04, 4월 27일 화요일 오전 10시

- check_cmd_path: execution execve로 변경, 파일의 절대경로 검색 후 cmd->argv[0] 갱신
- operate_pipe(): t_cmd 설정하고 각 cmd간 pipe연결 처리
- replace(): cmd의 args에서 $, ~($HOME)등으로 replace해서 처리


### 05, 4월  29일 목요일 오전 10시

-  Builtin 함수들 연결
-  getpwd()로 읽어서 env의 PWD에 write, cd가 호출될 때마다 PWD와 OLDPWD도 같이 처리 (PWD 변경전에 update)
-  $?와 g_tag.status 연결
-  절대경로 path 찾을 때 없는 패스의 경우 예외처리 (path=/hello)


### 06, 5월 4일 화요일 12시 슬랙 미팅


- 파싱 부분 replace 보완: echo로 테스트

  - [x] echo aaa"aaa"
  - [x] echo aaa"aaa aaa"
  - [x] echo "aaa""bbb"
  - [x] echo "aaa'bbb ccc'ddd"
  - [x] echo 'aaa"bbb ccc"ddd'
  - [x] echo "aaa aaa"aaaa
  - [x] echo $PATH:$HOME
  - [x] echo "$HOME"
  - [x] echo '$HOME'
  - [x] echo $?
  - [x] echo $HO"ME" = ME
  - [x] echo $"HOME" = HOME
  - [x] echo "'$HOME'" = /Users/seongcho
  - [x] echo "\\$HOME \\\$HOME \\\\$HOME $HOME $HOME $HOME"




- cmd args에 redirect 있는 경우 별도 처리
  - [x] pipe랑 충돌은 없을 것 같음
  - [x] ls  > a.out | wc | hello
  - [x] ls > a.txt > b.txt > c.txt
- todo: $?의 값 builtin에서 상황에 따라 설정

  - [x] cd
  - [x] exit
  - [x] unset
  - [x] export (인자 없이 사용시 소팅된 env list 출력)
  - [x] execute()
  - [x] pwd
  - [x] echo
  - [x] env

- todo: cmd syntax 기본 에러 체크 (ls -al | 에러처리, 멀티라인처리안해도 되기 때문에 )
  - [x] exec_test ‘;; test’
  - [x] exec_test ‘| test’
  - [x] exec_test ‘echo > <’
  - [x] exec_test ‘echo >’
  - [x] exec_test ‘echo >>’
  - [x] exec_test ‘> a.txt echo hello; wc < a.txt’
  - [x] exec_test ‘echo | |’
  - [x] echo "\\$hello"
  - [x] echo "\\"hello"
  - [x] echo '"'"hello" = "hello
  - [x] echo '\\'"   "
  - [x] echo \\\\"    " = \
  - [x] echo "\\$\tttaaa bbb"
  - [x] echo "'$'" = '$'


- todo: 잘못된 인자들 + 알파
  - [x] exec_test “exit 42 53 68"
  - [x] exec_test “exit 9223372036854775807"
  - [x] exec_test “exit -9223372036854775808”
  - [ ] exec_test “exit 9223372036854775808"
  - [ ] exec_test “exit -9223372036854775810”
  - [ ] exec_test “gdagadgag”
  - [ ] exec_test “ls -Z”
  - [ ] exec_test “cd gdhahahad”
  - [ ] exec_test “ls -la | wtf”


### 07, 5월 5일 수요일 12시 서초 미팅

- todo: termios char 하나씩 입력받는 모드에서 gnl 대신할 라인 입력모드 만들기
  - [x] 기본 구조 생성 in termmode.c
  - [x] gnl대신 하는 구조 생성
  - [x] backspace
  - [x] up and down
  - [x] history와 연결
  - [x] Signal 처리

- todo: parsing and check syntax error
  - [x] 기본 parser
  - [x] 기존 syntax 체크 함수 업데이트
  - [x] g_tag.input과 연결
  - [x] <> >< 처리
  - [x] " " 밖의 $값들 env로 읽어서 key가 없으면 스페이스 처리, $HO"ME", $"HOME"
  - [x] $1 처리, echo $|wc 처리, echo $ HOME 처리
  - [x] \\"asd '"'asd로 변경?

- syntax 기본 에러 체크에서 " " 부분 때문에 처리하지 못한 부분: 일단 그냥 두고 진행해보는 걸로...

  - [x] exec_test ‘ls ;; ls’
  - [x] exec_test ‘ls  ";;" ls’
  - [x] exec_test ‘ls || ls’
  - [x] exec_test ‘ls  "||" ls’



### 08, 5월 6일 목요일 12시 서초 미팅

- [x] history 재 코딩 및 커서처리
- [x] 문자열 syntax 처리를 위한 파싱 후 기본적인 에러 처리
- [x] " " 안의 $, \ 처리를 위한 repace를 미리 수행

- [x] 일단 replace는 set_cmd 전에 다 처리해서 넘기는 걸로 했습니다. 아래의 네가지 경우 set_cmd 쪽에서 따옴표 핸들링 하는 쪽에서 처리 가능할까요?  첫번째 경우는 이상한 노이즈가 끼는 문제이고, 세번째 네번째 경우는 set_cmd로 넘길때는 동일한 패턴이 됩니다.그런데 뒤에 "  "속에 스페이스가 들어있으면 죽어버립니다.

```shell
echo "aaa aaa"aaaa
aaa aaaaaaa�������� 뒤에 이상한 게 붙어요... 왜 그럴까요?
echo "a "a
a a���
echo '"'"hello"
"hello 가 나와야 하는데 "'hello로 나와요
echo \\"  "
파싱에서 \\를 '\'"  "로 변경해서 넘겨서 \  가 나와야 하는데 미니쉘이 죽어요...
echo 'a'"  "
```

따옴표 쪽 보려면 minishell.c에서 아래 주석 처리되어있는 gnl을 풀고 termios, termcap 부분 주석처리하면 set_cmd쪽  따옴표쪽 핸들링 코드 디버깅 해 보는 건 문제없을 겁니다. 그리고, syntax1.c의  check_basic_syntax_error()의 주석부분 해제하면 input 파싱한 결과를 볼 수 있습니다.

```c
/*
get_next_line(0, input);
(void)ncinput;
*/
///*
tag->is_cmd = 1;
non_canonical_init(0);
ncinput = non_canonical_input();
non_canonical_init(1);
tag->is_cmd = 0;
*input = ncinput.input;
if (ncinput.input == NULL)
	*input = ft_strdup("");
//*/
```

```c
/*
	printf("---\n");
	print_pars(&g_tag, 1);
	printf("[parsed]%s\n", g_tag.parsed);
	printf("---\n");
*/
```

어제 말한 테스트 케이스 4개중 2, 3, 4 는 | 처리후 split 타기 직전에 " " 문자열이 있는 경우 앞뒤   "를 제거하는 방식으로 해결했어요.. 이 방식으로 첫번째 테스트 케이스도 해결은 되었는데 똑같은 패턴의 노이즈가 ' '일 경우 발생합니다.  푸쉬해놨습니다.... 놈은 아직 못맞췄어요...

- [x] 그래서 정리해보면, 어제의 4개의 테스트케이스는 일단 해결된 것같구요.. split할때는 ' ' 경우만 생각하고 봐주시면 될 것 같습니다. 아래 또 다시 4가지 해결해야할 테스트케이스가 생겼습니다.

```shell
echo aaa'bbb ccc'ddd
echo 'b 'a
echo \\' '

echo "\"hello" <- 이런 경우는 echo \"hello로 변해서 split으로 넘어가며 split에서 처리해주던 부분을 처리안하게 바꾸어 그대로 "hello가 출력되게 해야 할 것 같아요..
```



### 09, 5월 9일 일요일 152시 서초 미팅

- [ ] 코드 정리
- [ ] 놈 체크
- [ ] 테스트
- [ ] project finish & 평가 start



### (5월 첫주 평가받는 것을 목표로!)



## 4. 개발 내용 정리

- pipe와 semicolon 파싱
- 파싱: 문자열, 연산자, 리다이렉션 으로 구분, 연산자로 끝나는 등의 파싱 에러이면 bash0 error

  ```c
  NORM, SPCE, SINQ, DOUQ, BSLA, DOLR,
  PIPE, DPIP, SEMC, DSEM,
  RIGT, DRGT, LEFT
  ```

- termios, termcap 처리

- mini와 bash like 에 집중
  - 기본적인 syntax error 체크

  - | 병렬 처리 안함

  - " ", ' ', $, ~ 등 input 파싱단계에서 replace 처리




## 5. 배운점 및 개선할 점



- 설계의 중요성
- 프로시저, 데이터 diagram 그리기
- 소통

  - 공통함수 (문서), 변수명, 함수명, 함수의 return값(0) 정의
  - 작업내용 문서화
- 여러명이서 디스코드를 현실처럼 셋팅하고 쓰기
- git

  - commmit 한개의 일만... 작게..
  - pull request



