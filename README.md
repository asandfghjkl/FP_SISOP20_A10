# FP_SISOP20_A10
**Sandra Agnes Oktaviana  (05111840000124)**

**Adrian Danindra Indarto (05111840000068)**

## table of contents
- [x] [touch](https://github.com/asandfghjkl/FP_SISOP20_A10#touch)
- [ ] [mv](https://github.com/asandfghjkl/FP_SISOP20_A10#mv)
- [ ] [find](https://github.com/asandfghjkl/FP_SISOP20_A10#find)
- [x] [cmp](https://github.com/asandfghjkl/FP_SISOP20_A10#cmp)
- [ ] [zip](https://github.com/asandfghjkl/FP_SISOP20_A10#zip)

## source code 
* [touch](https://github.com/asandfghjkl/FP_SISOP20_A10/blob/master/touch/touch.c)
* [cmp](https://github.com/asandfghjkl/FP_SISOP20_A10/blob/master/cmp/cmp.c)

## touch
Perintah ini digunakan untuk mengganti timestamp sebuah file ke waktu sekarang apabila file sudah tersedia atau membuat file kosong apabila file belum tersedia. 

## mv
Perintah ini digunakan untuk memindahkan file-file ke folder tujuan.
Terdapat 2 opsi untuk menjalankannya:
* biasa

  untuk menggunakan opsi ini, maka diperlukan path to file yang akan dipindahkan.
  contoh: `mv /path/to/file.txt /new/path/`
  
* \*

  opsi ini digunakan untuk memindahkan seluruh file di cwd ke path baru.
  contoh: `mv * /new/path/`

## find
Perintah ini digunakan untuk mencari file di directory. Perintah ini bersifat rekursif. 

## cmp
Membandingkan 2 file byte per byte.
contoh: cmp file1.c file2.c 
        -> outputnya menunjukkan kedua file tersebut tidak sama pertama kali di byte ke-berapa dan line ke-berapa

## zip
Perintah untuk mengkompresi file.
Terdapat 3 opsi untuk menjalankannya:
* biasa

  untuk zip file biasa, bisa lebih dari 1 file.
  contoh: `zip tes.zip tes.txt` (zip file tes.txt ke file tes.zip) 
* -m

  untuk menghapus file asli setelah dilakukan zip.
  contoh: `zip –m tes.zip tes.txt` (menghapus file test.txt setelah di zip) 
  
* -r

  untuk melakukan zip file secara rekursif dalam suatu direktori
  contoh: `zip -r zipfile.zip direktori` (untuk zip file di direktori secara rekursif) 
 
