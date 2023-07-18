# MINIRT

## 프로젝트 목표

- 이 프로젝트의 목표는 C 언어와 OpenGL로 제작된 Mlx Library를 활용하여 픽셀 단위의 Ray Tracing을 구현하는 것입니다. 이를 통해 구, 평면, 원기둥과 같은 3차원 객체를 벡터 개념으로 추적하여 ViewPort에 시각적으로 표현합니다.

- Ray Tracing은 광선을 추적하여 빛의 반사, 굴절, 그림자 등을 계산하여 사실적인 그래픽을 생성하는 기술입니다. 이 프로젝트는 Mlx Library를 활용하여 이러한 Ray Tracing을 구현하고, 3차원 객체를 조작하여 화면에 렌더링합니다.

- 이 프로젝트는 C 언어와 OpenGL, Mlx Library를 이해하고 활용하는 능력을 향상시키는 동시에, 컴퓨터 그래픽스와 광학의 기본 원리에 대한 이해를 높이는 것을 목표로 합니다.

### Ray Tracing
- Ray Tracing은 컴퓨터 그래픽스에서 현실적인 광원 및 그림자, 굴절, 반사 등의 광학적 효과를 시뮬레이션하기 위한 강력한 기술입니다. 이 기술은 렌더링 프로세스에서 광선을 따라 객체와 교차점을 추적하여 시각적인 결과물을 생성합니다.

- Ray Tracing의 기본 개념은 간단합니다. 장면(Scene)에 있는 모든 객체는 광원과 상호작용하는 광선(Ray)으로 표현됩니다. 이 광선은 카메라에서 출발하여 픽셀 단위로 화면(ViewPlane)을 향해 발사됩니다. 광선은 장면 내의 객체와 교차하는 지점을 찾기 위해 반복적으로 추적됩니다.
![image](https://github.com/bingu-k/MINIRT/assets/74482282/f5229c4b-6950-4032-8a6d-df9c350c69bd)

- 각 광선이 장면 내의 객체와 교차하는 경우, 교차점에서 반사, 굴절, 그림자 등의 광학적 효과를 계산하여 픽셀의 색상을 결정합니다. 이렇게 모든 픽셀에 대해 광선 추적을 반복하고 계산하여 최종적으로 현실적인 그래픽을 생성합니다.

- Ray Tracing은 사실적이고 자연스러운 빛과 그림자, 굴절 효과를 재현할 수 있어 영화, 게임 및 시각화 분야에서 널리 사용됩니다. 하지만 계산량이 많고 복잡한 알고리즘이기 때문에 실시간 렌더링에는 적합하지 않습니다. 대신, 정적인 이미지나 사전 계산된 애니메이션 등에 사용됩니다.


---
## 파일 구조
```text
📦MINIRT
 ┣ 📂include
 ┃ ┣ 📜get_next_line.h
 ┃ ┣ 📜minirt.h
 ┃ ┗ 📜struct.h
 ┣ 📂mlx
 ┃ ┣ 📜Makefile
 ┃ ┣ 📜font.c
 ┃ ┣ 📜font.xcf
 ┃ ┣ 📜mlx.h
 ┃ ┣ 📜mlx_init_loop.m
 ┃ ┣ 📜mlx_int.h
 ┃ ┣ 📜mlx_int_str_to_wordtab.c
 ┃ ┣ 📜mlx_mouse.m
 ┃ ┣ 📜mlx_new_image.m
 ┃ ┣ 📜mlx_new_window.h
 ┃ ┣ 📜mlx_new_window.m
 ┃ ┣ 📜mlx_opengl.h
 ┃ ┣ 📜mlx_opengl.m
 ┃ ┣ 📜mlx_png.c
 ┃ ┣ 📜mlx_png.h
 ┃ ┣ 📜mlx_rgb.c
 ┃ ┣ 📜mlx_shaders.c
 ┃ ┗ 📜mlx_xpm.c
 ┣ 📂scene
 ┃ ┣ 📜basic.rt
 ┃ ┣ 📜color_err.rt
 ┃ ┣ 📜empty.rt
 ┃ ┣ 📜fov_err1.rt
 ┃ ┣ 📜fov_err2.rt
 ┃ ┣ 📜large_space.rt
 ┃ ┣ 📜multi_object.rt
 ┃ ┣ 📜no_ambient.rt
 ┃ ┣ 📜no_canvas.rt
 ┃ ┣ 📜norm_err1.rt
 ┃ ┣ 📜norm_err2.rt
 ┃ ┣ 📜norm_err3.rt
 ┃ ┣ 📜test1.rt
 ┃ ┣ 📜test2.rt
 ┃ ┣ 📜test3.rt
 ┃ ┣ 📜test_multi_plane.rt
 ┃ ┗ 📜test_room.rt
 ┣ 📂src
 ┃ ┣ 📂parsing
 ┃ ┃ ┣ 📜check.c
 ┃ ┃ ┣ 📜create.c
 ┃ ┃ ┣ 📜create_object.c
 ┃ ┃ ┣ 📜get_next_line.c
 ┃ ┃ ┣ 📜get_next_line_utils.c
 ┃ ┃ ┣ 📜info.c
 ┃ ┃ ┣ 📜set.c
 ┃ ┃ ┣ 📜set_cylinder.c
 ┃ ┃ ┣ 📜set_object.c
 ┃ ┃ ┣ 📜set_plane.c
 ┃ ┃ ┣ 📜set_sphere.c
 ┃ ┃ ┣ 📜split.c
 ┃ ┃ ┣ 📜util1.c
 ┃ ┃ ┗ 📜util2.c
 ┃ ┣ 📂rendering
 ┃ ┃ ┣ 📜hit.c
 ┃ ┃ ┣ 📜hit_object.c
 ┃ ┃ ┣ 📜mlx_util.c
 ┃ ┃ ┣ 📜phong.c
 ┃ ┃ ┣ 📜render.c
 ┃ ┃ ┣ 📜vector1.c
 ┃ ┃ ┗ 📜vector2.c
 ┃ ┗ 📜main.c
 ┗ 📜Makefile
```
---
## 프로젝트 실행
``` bash
cd ./mlx
make
../
make
./miniRT ./scene/<config 파일>
```
### Example Result
``` bash
./miniRT ./scene/multi_object.rt
```
<img width="1136" alt="Screenshot 2023-07-18 at 2 24 42 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/67383812-f0e7-4044-81d3-860315395f73">




## MLX 예제
### ex01
- 목표
  500x500의 화면을 띄운다.
- 실행 방법
  ``` bash
  make
  ./test
  ```
  <img width="495" alt="Screenshot 2023-07-18 at 2 11 23 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/c1f5211a-47b4-4937-85e9-d7187536a613">

### ex02
- 목표
  key 입력을 받아 출력로그를 띄운다.
- 실행 방법
  ``` bash
  make
  ./test
  ```
  <img width="495" alt="Screenshot 2023-07-18 at 2 11 23 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/c1f5211a-47b4-4937-85e9-d7187536a613">
  <img width="444" alt="Screenshot 2023-07-18 at 2 22 52 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/3d8325e5-8179-4fae-8cb1-e28b99cd6b14">

### ex03
- 목표
  화면에 그라데이션을 입힌다.
- 실행 방법
  ``` bash
  make
  ./gradation
  ```
  <img width="368" alt="Screenshot 2023-07-18 at 2 15 49 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/dbdcd911-6b6c-4fe1-8a02-550aabe65a8f">

### ex04
- 목표
  화면에 하늘을 표현한다.
- 실행 방법
  ``` bash
  make
  ./sky
  ```
  <img width="912" alt="Screenshot 2023-07-18 at 2 16 52 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/e2238c5f-04cc-4ee2-8945-613879e32042">

### ex05
- 목표
  하늘을 표현한 화면에 빨간색 구를 표현한다.
- 실행 방법
  ``` bash
  make
  ./sphere
  ```
  <img width="912" alt="Screenshot 2023-07-18 at 2 17 31 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/abefb211-fe08-4518-a74b-8a51fa01ecbe">

### ex06
- 목표
  하늘을 표현한 화면에 그라데이션 구를 표현한다.
- 실행 방법
  ``` bash
  make
  ./sphere_gradation
  ```
  <img width="912" alt="Screenshot 2023-07-18 at 2 18 19 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/b4f7c00b-f4fe-41fa-8473-cf13ea02a63d">

### ex07
- 목표
  하늘을 표현한 화면에 그라데이션 구를 표현하고, 땅을 표현한 구를 추가한다.
- 실행 방법
  ``` bash
  make
  ./sphere_gradation
  ```
  <img width="912" alt="Screenshot 2023-07-18 at 2 19 43 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/f8c44350-5b18-420d-833a-d3c0e0c22c1a">

### ex08
- 목표
  Phong Shading을 표현하기 위한 Ambient Lighting을 구현한다.
- 실행 방법
  ``` bash
  make
  ./ambient_lighting
  ```
  <img width="912" alt="Screenshot 2023-07-18 at 2 21 00 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/72f73dc4-adee-41ab-b0f5-f9d7bc797a1b">

### ex09
- 목표
  Phong Shading을 구현한다.
- 실행 방법
  ``` bash
  make
  ./phong_model
  ```
  <img width="912" alt="Screenshot 2023-07-18 at 2 21 32 PM" src="https://github.com/bingu-k/MINIRT/assets/74482282/93eaf182-b99c-41de-8283-9e3f01d3c24f">
---
### 참조
https://raytracing.github.io/books/RayTracingInOneWeekend.html
