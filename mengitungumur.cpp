#include <iostream>
#include <ctime>

using namespace std;

void hitungUmur(int day, int month, int year, int& umur_tahun, int& umur_bulan, int& umur_hari) {
    time_t t = time(0);
    tm* now = localtime(&t);

    int hari_ini = now->tm_mday;
    int bulan_ini = now->tm_mon + 1;
    int tahun_ini = now->tm_year + 1900;

    umur_tahun = tahun_ini - year;
    umur_bulan = bulan_ini - month;
    umur_hari = hari_ini - day;

    if (umur_bulan < 0) {
        umur_tahun--;
        umur_bulan += 12;
    }

    if (umur_hari < 0) {
        umur_bulan--;
        if (umur_bulan < 0) {
            umur_bulan += 12;
            umur_tahun--;
        }
        int days_in_previous_month = (bulan_ini == 1 || bulan_ini == 3 || bulan_ini == 5 || bulan_ini == 7 || bulan_ini == 8 || bulan_ini == 10 || bulan_ini == 12) ? 31 : (bulan_ini == 4 || bulan_ini == 6 || bulan_ini == 9 || bulan_ini == 11) ? 30 : (tahun_ini % 4 == 0 && (tahun_ini % 100 != 0 || tahun_ini % 400 == 0)) ? 29 : 28;
        umur_hari += days_in_previous_month;
    }
}

int main() {
    int day, month, year;
    int umur_tahun, umur_bulan, umur_hari;

    cout << "Masukkan tanggal lahir (dd mm yyyy): ";
    cin >> day >> month >> year;

    hitungUmur(day, month, year, umur_tahun, umur_bulan, umur_hari);

    cout << "Umur Anda adalah: " << umur_tahun << " tahun, " << umur_bulan << " bulan, dan " << umur_hari << " hari." << endl;

    return 0;
}