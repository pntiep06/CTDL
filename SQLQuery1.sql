-- Tạo database
CREATE DATABASE QuanLyTourDuLich;
GO

USE QuanLyTourDuLich;
GO

-- 1. Tạo bảng TINHTHANH
CREATE TABLE TINHTHANH (
    MaTTP VARCHAR(10) PRIMARY KEY,
    TenTTP NVARCHAR(100) NOT NULL,
    Mien NVARCHAR(20) NOT NULL
);

-- 2. Tạo bảng DIADIEMDULICH
CREATE TABLE DIADIEMDULICH (
    MaDDL VARCHAR(10) PRIMARY KEY,
    TenDDL NVARCHAR(200) NOT NULL,
    DacTrung NVARCHAR(50) NOT NULL,
    MaTTP VARCHAR(10) NOT NULL,
    FOREIGN KEY (MaTTP) REFERENCES TINHTHANH(MaTTP)
);

-- 3. Tạo bảng TOUR
CREATE TABLE TOUR (
    MaTour VARCHAR(10) PRIMARY KEY,
    TenTour NVARCHAR(200) NOT NULL,
    SoNgay INT NOT NULL,
    SoDem INT NOT NULL,
    PhuongTienDi NVARCHAR(50) NOT NULL,
    PhuongTienVe NVARCHAR(50) NOT NULL,
    GiaLe DECIMAL(18,0) NOT NULL,
    GiaNhom DECIMAL(18,0) NOT NULL
);

-- 4. Tạo bảng CHITIET_TOUR_DDL
CREATE TABLE CHITIET_TOUR_DDL (
    MaTour VARCHAR(10),
    MaDDL VARCHAR(10),
    SoNgay INT NOT NULL,
    SoDem INT NOT NULL,
    PRIMARY KEY (MaTour, MaDDL),
    FOREIGN KEY (MaTour) REFERENCES TOUR(MaTour),
    FOREIGN KEY (MaDDL) REFERENCES DIADIEMDULICH(MaDDL)
);
-- Nhập dữ liệu TINHTHANH
INSERT INTO TINHTHANH VALUES
('TTP01', N'Hà Nội', N'Miền Bắc'),
('TTP02', N'Hồ Chí Minh', N'Miền Nam'),
('TTP03', N'Đà Nẵng', N'Miền Trung'),
('TTP04', N'Quảng Ninh', N'Miền Bắc'),
('TTP05', N'Khánh Hòa', N'Miền Trung'),
('TTP06', N'Lâm Đồng', N'Miền Nam'),
('TTP07', N'Bà Rịa Vũng Tàu', N'Miền Nam');

-- Nhập dữ liệu DIADIEMDULICH
INSERT INTO DIADIEMDULICH VALUES
('DDL01', N'Vịnh Hạ Long', N'Tắm biển', 'TTP04'),
('DDL02', N'Hồ Hoàn Kiếm', N'Thăm quan', 'TTP01'),
('DDL03', N'Bãi biển Mỹ Khê', N'Tắm biển', 'TTP03'),
('DDL04', N'Bà Nà Hills', N'Leo núi', 'TTP03'),
('DDL05', N'Đảo Hòn Tre', N'Tắm biển', 'TTP05'),
('DDL06', N'Đà Lạt', N'Thăm quan', 'TTP06'),
('DDL07', N'Núi Bà Đen', N'Leo núi', 'TTP06'),
('DDL08', N'Bãi Sau Vũng Tàu', N'Tắm biển', 'TTP07');

-- Nhập dữ liệu TOUR
INSERT INTO TOUR VALUES
('T01', N'Tour Hạ Long 2N1Đ', 2, 1, N'Ô tô', N'Ô tô', 2500000, 1800000),
('T02', N'Tour Đà Nẵng 3N2Đ', 3, 2, N'Máy bay', N'Máy bay', 4500000, 3800000),
('T03', N'Tour Nha Trang 4N3Đ', 4, 3, N'Máy bay', N'Ô tô', 5000000, 4200000),
('T04', N'Tour Đà Lạt 2N1Đ', 2, 1, N'Ô tô', N'Ô tô', 1800000, 1500000),
('T05', N'Tour Vũng Tàu 2N1Đ', 2, 1, N'Ô tô', N'Ô tô', 1500000, 1200000),
('T06', N'Tour Miền Trung 5N4Đ', 5, 4, N'Máy bay', N'Máy bay', 6000000, 5000000),
('T07', N'Tour Hạ Long VIP', 3, 2, N'Máy bay', N'Ô tô', 3500000, 2800000);

-- Nhập dữ liệu CHITIET_TOUR_DDL
INSERT INTO CHITIET_TOUR_DDL VALUES
('T01', 'DDL01', 1, 1),
('T01', 'DDL02', 1, 0),
('T02', 'DDL03', 2, 1),
('T02', 'DDL04', 1, 1),
('T03', 'DDL05', 3, 2),
('T03', 'DDL03', 1, 1),
('T04', 'DDL06', 2, 1),
('T05', 'DDL08', 2, 1),
('T06', 'DDL03', 2, 2),
('T06', 'DDL04', 1, 1),
('T06', 'DDL05', 2, 1),
('T07', 'DDL01', 2, 2);

select * From Tour

SELECT DISTINCT Tour.MaTour, Tour.TenTour
FROM TOUR 
INNER JOIN CHITIET_TOUR_DDL ON Tour.MaTour = CHITIET_TOUR_DDL.MaTour
INNER JOIN DIADIEMDULICH ON CHITIET_TOUR_DDL.MaDDL = DIADIEMDULICH.MaDDL
WHERE Tour.PhuongTienDi = N'Máy bay' 
  AND Tour.PhuongTienVe = N'Ô tô'
  AND DIADIEMDULICH.DacTrung = N'Tắm biển'
--INNER JOIN để kết nối các bảng( 2 bảng có mã tour, 2 bảng có mã du lịch => kết nối ch máy hiểu)
--DISTINCT để loại bỏ trùng lặp
--WHERE lọc điều kiện

SELECT TOP 1 TinhThanh.TenTTP
FROM TinhThanh
INNER JOIN DIADIEMDULICH ON TinhThanh.MaTTP = DIADIEMDULICH.MaTTP
GROUP BY TinhThanh.MaTTP, TinhThanh.TenTTP
ORDER BY COUNT(DIADIEMDULICH.MaDDL) DESC;

--GROUP BY nhóm theo tỉnh/thành phố
--COUNT() đếm số điểm du lịch
--ORDER BY ... DESC sắp xếp giảm dần (ASC tăng) 


SELECT DISTINCT TT.MaTTP, TT.TenTTP
FROM TINHTHANH TT
WHERE EXISTS (
    SELECT 1 FROM DIADIEMDULICH DDL1 
    WHERE DDL1.MaTTP = TT.MaTTP AND DDL1.DacTrung = N'Tắm biển'
)
AND EXISTS (
    SELECT 1 FROM DIADIEMDULICH DDL2 
    WHERE DDL2.MaTTP = TT.MaTTP AND DDL2.DacTrung = N'Leo núi'
);
--Sử dụng 2 EXISTS để kiểm tra tồn tại cả 2 đặc trưng
--Điều kiện AND đảm bảo cả 2 đều phải có

SELECT T.MaTour, T.TenTour, T.SoNgay, T.SoDem, T.GiaLe
FROM TOUR T
INNER JOIN CHITIET_TOUR_DDL CT ON T.MaTour = CT.MaTour
INNER JOIN DIADIEMDULICH DDL ON CT.MaDDL = DDL.MaDDL
WHERE DDL.TenDDL LIKE N'%Hạ Long%'
ORDER BY T.SoNgay DESC;
--LIKE với % để tìm kiếm tên chứa "Hạ Long"D


SELECT DISTINCT TT.MaTTP, TT.TenTTP
FROM TINHTHANH TT
WHERE EXISTS (
    SELECT 1 FROM DIADIEMDULICH DDL1 
    WHERE DDL1.MaTTP = TT.MaTTP AND DDL1.DacTrung = N'Tắm biển'
)
AND NOT EXISTS (
    SELECT 1 FROM DIADIEMDULICH DDL2 
    WHERE DDL2.MaTTP = TT.MaTTP AND DDL2.DacTrung = N'Leo núi'
);
--EXISTS tồn tại
--NOT EXISTS ko tồn tại
Thứ tự tạo bảng: Luôn tạo bảng cha trước, bảng con sau
INNER JOIN: Kết hợp dữ liệu từ nhiều bảng
GROUP BY + COUNT: Đếm và nhóm dữ liệu
EXISTS/NOT EXISTS: Kiểm tra sự tồn tại
Phép chia: Sử dụng 2 lớp NOT EXISTS
DISTINCT: Loại bỏ trùng lặp
LIKE: Tìm kiếm chuỗi con
ORDER BY: Sắp xếp kết quả