String_Matching_Project/
├── include/                <-- Các file .h (Bản thiết kế)
│   ├── algorithms.h        (Khai báo các hàm tìm kiếm: KMP, BF, BM...)
│   ├── cli_parser.h        (Khai báo hàm đọc tham số dòng lệnh)
│   ├── data_generator.h    (Khai báo hàm đọc file/tạo chuỗi ngẫu nhiên)
│   └── executor.h          (Khai báo hàm điều phối & đo đạc hiệu năng)
├── src/                    <-- Các file .cpp (Thực thi)
│   ├── algorithms/         (Logic thuật toán)
│   │   ├── brute_force.cpp
│   │   ├── kmp.cpp
│   │   └── ...
│   ├── processing/         (Xử lý hệ thống)
│   │   ├── cli_parser.cpp   (Xử lý -algo, -path, -pattern)
│   │   ├── data_generator.cpp (Đọc dữ liệu từ file .txt)
│   │   └── executor.cpp     (Chạy thuật toán, đếm phép so sánh, tính ms)
│   └── main.cpp            (Nơi kết nối tất cả các thành phần)
└── data/                   (Chứa các file test .txt)