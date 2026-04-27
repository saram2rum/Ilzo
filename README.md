# Ilzo

순수 C++로 바닥부터 직접 깎아보는 전통적인 체스 엔진 프로젝트입니다.
신경망(NNUE) 등의 블랙박스 모델을 배제하고, 오직 C++ 레벨의 로우레벨 제어와 알고리즘 최적화에 집중하는 것을 목표로 합니다.

## Status
Work in Progress.
현재 비트보드(Bitboard) 기반 체스판 초기화 및 기본 기물 이동(Movegen)을 구현 중입니다.
(아직 엔진과 체스 대국은 불가능합니다.)

## Tech Stack
* Language: C++17
* Build: Makefile

## How to Build
컴파일 테스트용 명령어입니다. (Mac/Linux 권장)

```bash
make
./ilzo
make clean
```