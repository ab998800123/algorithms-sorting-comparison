# 排序演算法比較

演算法，以 C++Builder VCL 製作的排序演算法實作與計時比較程式。使用者可選擇排序方法、設定輸入資料參數，查看排序結果與執行時間，並將計時結果顯示為圖表。

## 排序方法

程式提供以下九種排序實作：

- Selection sort
- Insertion sort
- Bubble sort
- Recursive quick sort
- Iterative quick sort
- Recursive merge sort
- Iterative merge sort
- Heap sort
- Radix sort

## 操作方式

介面提供以下設定與操作：

- `N`：輸入資料筆數
- `range`：隨機產生資料的數值範圍
- `times`：執行測試的輪數
- 勾選要執行的排序方法，再按 `run`
- 選擇是否顯示原始資料與排序結果
- 按「建立圖表」查看各排序方法的計時結果

程式以 `clock()` 計算執行時間，畫面顯示的單位為秒。實際數值會受輸入資料與執行環境影響。

## 使用技術

- C++
- Embarcadero C++Builder
- VCL 圖形介面
- TeeChart 圖表元件

## 執行方式

1. 在 Windows 上使用 Embarcadero C++Builder 開啟 `Project3.cbproj`。
2. 編譯並執行專案。
3. 設定資料筆數、數值範圍與測試輪數，選擇排序方法後按 `run`。
4. 按「建立圖表」查看計時結果。

## 可直接開啟
Windows 使用者可以直接執行 `Win32/Debug/Project3.exe`，不必先用 C++Builder 編譯。

## 專案檔案

- `Project3.cbproj`：C++Builder 專案檔
- `Unit4.cpp`、`Unit4.h`：排序演算法、計時與介面事件程式
- `Unit4.dfm`：VCL 表單與元件設定
