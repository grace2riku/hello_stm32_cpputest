# hello_stm32_cpputest
STM32の統合開発環境STM32CubeIDEにCppUTestを環境構築しTDDする

# 使い方
こちらの[Qiita記事](https://qiita.com/juraruming/items/2fbf398b9587757b17a2)を参照ください。

## シリアルコンソール通信設定
* 115200bps, データ長8bit, パリティなし, ストップビット1bit

# テストの例
* [C++学習用テスト](446re_test/cpp_lerning_test)


# ライセンス
## 446re_test
[Drivers/CMSIS/](https://github.com/grace2riku/hello_stm32_cpputest/tree/main/446re_test/Drivers/CMSIS): Apache License Version 2.0

[Drivers/STM32F4xx_HAL_Driver/](https://github.com/grace2riku/hello_stm32_cpputest/tree/main/446re_test/Drivers/STM32F4xx_HAL_Driver): BSD-3-Clause

## cpputest_library
CppUTestはBSD-3-Clause。

[Src/CppUTest/](https://github.com/grace2riku/hello_stm32_cpputest/tree/main/cpputest_library/Src/CppUTest)

[Src/CppUTestExt/](https://github.com/grace2riku/hello_stm32_cpputest/tree/main/cpputest_library/Src/CppUTestExt)

[Src/Platforms/Gcc/](https://github.com/grace2riku/hello_stm32_cpputest/tree/main/cpputest_library/Src/Platforms/Gcc)

[include/](https://github.com/grace2riku/hello_stm32_cpputest/tree/main/cpputest_library/include)
