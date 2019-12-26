/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"
#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */
using namespace std;

void Initialization()
{
    // If you use global variables, please initialize them explicitly in this function.
}

void Finalization()
{
    // Release your data before exiting
}

void ProcessRequest(const char *pRequest, void *pData, void *&pOutput, int &N)
{
    // TODO: Implement this function for processing a request
    // NOTE: You can add other functions to support this main process.
    //       pData is a pointer to a data structure that manages the dataset
    //       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
    //       N is the size of output, must be a non-negative number
    string khang = pRequest;
    TDataset *data = (TDataset *)pData;
    stringstream ss;
    ss << (char *)khang.data();
    char hgkhang[1000];
    string s;
    ss.getline(hgkhang, 1000, ' ');
    s = hgkhang;
    int u = 0;
    while (pRequest[u] != '\0')
        u++;
    if (s == "CL")
    {
        if (u == 2)
        {
            int *a = new int[1];
            a[0] = data->line.getSize();
            pOutput = a;
            N = 1;
        }
        else if (u == 3) {
            pOutput = nullptr;
            N = 0;
        }
        else
        {
            ss.getline(hgkhang, 1000);
            s = hgkhang;
            int k = 0;
            L1Item<City> *kh = data->city.get_Head();
            for (int i = 0; i < data->city.getSize(); i++)
                if (s == kh->data.name)
                {
                    k = 1;
                    break;
                }
                else
                    kh = kh->pNext;
            if (k == 0)
            {
                int *a = new int[1];
                a[0] = -1;
                pOutput = a;
                N = 1;
                return;
            }
            string id_city = kh->data.id;
            L1Item<Line> *kh1 = data->line.get_Head();
            int count = 0;
            while (kh1 != NULL)
            {
                if (id_city == kh1->data.city_id)
                    count++;
                kh1 = kh1->pNext;
            }
            int *a = new int[1];
            a[0] = count;
            pOutput = a;
            N = 1;
        }
    }
    else if (s == "LSC" && u >= 5)
    {
        ss.getline(hgkhang, 1000);
        s = hgkhang;
        int k = 0;
        L1Item<City> *kh = data->city.get_Head();
        for (int i = 0; i < data->city.getSize(); i++)
            if (s == kh->data.name)
            {
                k = 1;
                break;
            }
            else
                kh = kh->pNext;
        if (k == 0)
        {
            int *a = new int[0];
            pOutput = a;
            N = 0;
            return;
        }
        string id_city = kh->data.id;
        L1Item<Station> *kh1 = data->station.get_Head();
        int count = 0;
        while (kh1 != NULL)
        {
            if (id_city == kh1->data.city_id)
                count++;
            kh1 = kh1->pNext;
        }
        int *a = new int[count];
        kh1 = data->station.get_Head();
        int temp = -1;
        while (kh1 != NULL)
        {
            if (id_city == kh1->data.city_id)
            {
                string pTemp = kh1->data.id;
                int length_pTem = 0;
                while (length_pTem != pTemp.length())
                    if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                        length_pTem++;
                    else
                        break;
                if (length_pTem == pTemp.length() && pTemp.length() != 0)
                {
                    temp++;
                    a[temp] = stoi(kh1->data.id);
                }
            }
            kh1 = kh1->pNext;
        }
        pOutput = a;
        N = temp + 1;
    }
    else if (s == "LLC" && u >= 5)
    {
        ss.getline(hgkhang, 1000);
        s = hgkhang;
        int k = 0;
        L1Item<City> *kh = data->city.get_Head();
        for (int i = 0; i < data->city.getSize(); i++)
            if (s == kh->data.name)
            {
                k = 1;
                break;
            }
            else
                kh = kh->pNext;
        if (k == 0)
        {
            int *a = new int[0];
            pOutput = a;
            N = 0;
            return;
        }
        string id_city = kh->data.id;
        L1Item<Line> *kh1 = data->line.get_Head();
        int count = 0;
        while (kh1 != NULL)
        {
            if (id_city == kh1->data.city_id)
                count++;
            kh1 = kh1->pNext;
        }
        int *a = new int[count];
        kh1 = data->line.get_Head();
        int temp = -1;
        while (kh1 != NULL)
        {
            if (id_city == kh1->data.city_id)
            {
                string pTemp = kh1->data.id;
                int length_pTem = 0;
                while (length_pTem != pTemp.length())
                    if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                        length_pTem++;
                    else
                        break;
                if (length_pTem == pTemp.length() && pTemp.length() != 0)
                {
                    temp++;
                    a[temp] = stoi(kh1->data.id);
                }
            }
            kh1 = kh1->pNext;
        }
        pOutput = a;
        N = temp + 1;
    }
    else if (s == "LSL" && u >= 5)
    {
        ss.getline(hgkhang, 1000);
        s = hgkhang;
        string pTemp = s;
        int length_pTem = 0;
        if (s[0] == '-') length_pTem++;
        while (length_pTem != pTemp.length())
            if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                length_pTem++;
            else
                break;
        if (length_pTem != pTemp.length() || pTemp.length() == 0)
        {
            pOutput = nullptr;
            N = 0;
            return;
        }
        int k = 0;
        L1Item<Station_line> *kh = data->sline.get_Head();
        int count = 0;
        while (kh != NULL)
        {
            if (s == kh->data.line_id)
                count++;
            kh = kh->pNext;
        }

        int *a = new int[count];
        int temp = -1;
        kh = data->sline.get_Head();
        while (kh != NULL)
        {
            if (s == kh->data.line_id)
            {
                string pTemp = kh->data.station_id;
                int length_pTem = 0;
                while (length_pTem != pTemp.length())
                    if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                        length_pTem++;
                    else
                        break;
                if (length_pTem == pTemp.length() && pTemp.length() != 0)
                {
                    temp++;
                    a[temp] = stoi(kh->data.station_id);
                }
            }
            kh = kh->pNext;
        }
        pOutput = a;
        N = temp + 1;
    }
    else if (s == "FC" && u >= 4)
    {
        ss.getline(hgkhang, 1000);
        s = hgkhang;
        int k = 0;
        L1Item<City> *kh = data->city.get_Head();
        for (int i = 0; i < data->city.getSize(); i++)
            if (s == kh->data.name)
            {
                k = 1;
                break;
            }
            else
                kh = kh->pNext;
        if (k == 0)
        {
            int *a = new int[0];
            a[0] = -1;
            pOutput = a;
            N = 1;
            return;
        }
        else
        {
            int *a = new int[0];
            string pTemp = kh->data.id;
            int length_pTem = 0;
            while (length_pTem != pTemp.length())
                if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                    length_pTem++;
                else
                    break;
            if (length_pTem == pTemp.length() && pTemp.length() != 0)
            {
                a[0] = stoi(kh->data.id);
            }
            else
                a[0] = -1;
            pOutput = a;
            N = 1;
        }
    }
    else if (s == "FS" && u >= 4)
    {
        ss.getline(hgkhang, 1000);
        s = hgkhang;
        int k = 0;
        L1Item<Station> *kh = data->station.get_Head();
        for (int i = 0; i < data->station.getSize(); i++)
            if (s == kh->data.name)
            {
                k = 1;
                break;
            }
            else
                kh = kh->pNext;
        if (k == 0)
        {
            int *a = new int[1];
            a[0] = -1;
            pOutput = a;
            N = 1;
            return;
        }
        int *a = new int[1];
        string pTemp = kh->data.id;
        int length_pTem = 0;
        while (length_pTem != pTemp.length())
            if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                length_pTem++;
            else
                break;
        if (length_pTem == pTemp.length() && pTemp.length() != 0)
        {
            a[0] = stoi(kh->data.id);
        }
        else
            a[0] = -1;
        pOutput = a;
        N = 1;
    }
    else if (s == "SLP" && u >= 5)
    {
        ss.getline(hgkhang, 1000, ' ');
        s = hgkhang;
        L1Item<Station> *kh = data->station.get_Head();
        while (kh != NULL)
        {
            if (s == kh->data.id)
                break;
            kh = kh->pNext;
        }
        ss.getline(hgkhang, 1000);
        s = hgkhang;
        L1Item<Track> *kh1 = data->track.get_Head();
        while (kh1 != NULL)
        {
            if (s == kh1->data.id)
                break;
            kh1 = kh1->pNext;
        }
        if (kh == NULL || kh1 == NULL)
        {
            int *a = new int[1];
            a[0] = -1;
            pOutput = a;
            N = 1;
        }
        else
        {
            string text1 = kh->data.geometry;
            string text2 = kh1->data.geometry;
            stringstream ss1;
            ss1 << (char *)text1.data();
            char ntp[10000];
            ss1.getline(ntp, 10000, '(');
            ss1.getline(ntp, 10000, ')');
            text1 = ntp;
            stringstream ss2;
            ss2 << (char *)text2.data();
            ss2.getline(ntp, 10000, '(');
            string _text;
            int index = 0;
            while (!ss2.eof())
            {
                ss2.getline(ntp, 10000, ',');
                _text = ntp;
                if (text1 == _text)
                {
                    int *a = new int[1];
                    a[0] = index;
                    pOutput = a;
                    N = 1;
                    return;
                }
                index++;
            }
            _text.pop_back();
            if (text1 == _text)
            {
                int *a = new int[1];
                a[0] = index - 1;
                pOutput = a;
                N = 1;
                return;
            }
            else
            {
                int *a = new int[1];
                a[0] = -1;
                pOutput = a;
                N = 1;
                return;
            }
        }
    }
    else if (s == "IS" && u >= 4)
    {
        L1Item<Station> *pNew = new L1Item<Station>();
        ss.getline(hgkhang, 1000, ',');
        pNew->data.name = hgkhang;
        ss.getline(hgkhang, 1000, ',');
        pNew->data.geometry = hgkhang;
        L1Item<Station> *kh = data->station.get_Head();
        int idmax = 0;
        int id_city_max = 0;
        while (kh != NULL)
        {
            string pTemp = kh->data.id;
            int length_pTem = 0;
            while (length_pTem != pTemp.length())
                if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                    length_pTem++;
                else
                    break;
            if (length_pTem == pTemp.length() && pTemp.length() != 0)
            {
                if (stoi(kh->data.id) > idmax)
                    idmax = stoi(kh->data.id);
            }

            pTemp = kh->data.city_id;
            length_pTem = 0;
            while (length_pTem != pTemp.length())
                if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                    length_pTem++;
                else
                    break;
            if (length_pTem == pTemp.length() && pTemp.length() != 0)
            {
                if (stoi(kh->data.city_id) > id_city_max)
                    id_city_max = stoi(kh->data.city_id);
            }

            kh = kh->pNext;
        }
        pNew->data.id = to_string(idmax + 1);
        pNew->data.city_id = to_string(id_city_max + 1);
        data->station.push_back(pNew->data);
        int *a = new int[1];
        a[0] = idmax + 1;
        pOutput = a;
        N = 1;
        return;
    }
    else if (s == "RS" && u >= 4)
    {
        ss.getline(hgkhang, 1000);
        s = hgkhang;
        int k = 0;
        int pos = -1;
        L1Item<Station> *kh = data->station.get_Head();
        while (kh != NULL)
        {
            pos++;
            if (kh->data.id == s)
            {
                k = 1;
                kh = kh->pNext;
                data->station.remove(pos);
                pos--;
            }
            else
                kh = kh->pNext;
        }
        pos = -1;
        L1Item<Station_line> *sk = data->sline.get_Head();
        while (sk != NULL)
        {
            pos++;
            if (sk->data.station_id == s)
            {
                k = 1;
                sk = sk->pNext;
                data->sline.remove(pos);
                pos--;
            }
            else
                sk = sk->pNext;
        }
        int *a = new int[1];
        if (k == 1)
            a[0] = 0;
        else
            a[0] = -1;
        pOutput = a;
        N = 1;
    }
    else if (s == "US" && u >= 4)
    {
        ss.getline(hgkhang, 1000, ' ');
        s = hgkhang;
        ss.getline(hgkhang, 1000, ',');
        string _name(hgkhang);
        ss.getline(hgkhang, 1000, ',');
        string _geometry(hgkhang);
        L1Item<Station> *kh = data->station.get_Head();
        while (kh != NULL)
        {
            if (kh->data.id == s)
            {
                kh->data.name = _name;
                kh->data.geometry = _geometry;
                kh->data.city_id = "-1";
                int *a = new int[1];
                a[0] = 0;
                pOutput = a;
                N = 1;
                return;
            }
            kh = kh->pNext;
        }
        int *a = new int[1];
        a[0] = -1;
        pOutput = a;
        N = 1;
        return;
    }
    else if (s == "ISL" && u >= 5)
    {
        ss.getline(hgkhang, 1000, ' ');
        s = hgkhang;
        ss.getline(hgkhang, 1000, ' ');
        string s1 = hgkhang;
        ss.getline(hgkhang, 1000);
        string s2 = hgkhang;
        string station_id = s;
        string line_id = s1;

        string pTemp = s2;
        int length_pTem = 0;
        while (length_pTem != pTemp.length())
            if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                length_pTem++;
            else
                break;
        if (length_pTem != pTemp.length() || pTemp.length() == 0)
        {
            int *a = new int[1];
            a[0] = -1;
            pOutput = a;
            N = 1;
            return;
        }
        int p_i = stoi(s2);
        int count = -1;
        L1Item<Station_line> *kh = data->sline.get_Head();
        int count1 = 0;
        while (kh != NULL)
        {
            count1++;
            if (kh->data.line_id == line_id)
            {
                count++;
                if (count == p_i)
                {
                    L1Item<Station_line> *pNew = new L1Item<Station_line>();
                    pNew->data.id = "-1";
                    pNew->data.station_id = station_id;
                    pNew->data.line_id = line_id;
                    pNew->data.city_id = "-1";
                    data->sline.insert(count1 - 1, pNew->data);
                    int *a = new int[1];
                    a[0] = 0;
                    pOutput = a;
                    N = 1;
                    return;
                }
            }
            else if (kh->pNext == NULL && count == p_i - 1 && count != -1)
            {
                L1Item<Station_line> *pNew = new L1Item<Station_line>();
                pNew->data.id = "-1";
                pNew->data.station_id = station_id;
                pNew->data.line_id = line_id;
                pNew->data.city_id = "-1";
                data->sline.insert(count1 - 1, pNew->data);
                int *a = new int[1];
                a[0] = 0;
                pOutput = a;
                N = 1;
                return;
            }
            kh = kh->pNext;
        }
        int *a = new int[1];
        a[0] = -1;
        pOutput = a;
        N = 1;
        return;
    }
    else if (s == "RSL" && u >= 5)
    {
        int *a = new int[1];
        ss.getline(hgkhang, 1000, ' ');
        s = hgkhang;
        ss.getline(hgkhang, 1000);
        string s1 = hgkhang;

        string pTemp = s1;
        int length_pTem = 0;
        while (length_pTem != pTemp.length())
            if (pTemp[length_pTem] >= '0' && pTemp[length_pTem] <= '9')
                length_pTem++;
            else
                break;
        if (length_pTem != pTemp.length() || pTemp.length() == 0)
        {
            a[0] = -1;
            pOutput = a;
            N = 1;
            return;
        }

        string station_id = s;
        string line_id = s1;
        L1Item<Station_line> *kh = data->sline.get_Head();
        L1Item<Station_line> *kh1 = data->sline.get_Head();
        if (kh->data.line_id == line_id && kh->data.station_id == station_id)
        {
            data->sline.removeHead();
            a[0] = 0;
            pOutput = a;
            N = 1;
            return;
        }
        else
        {
            int count = 0;
            while (kh != NULL)
            {
                kh1 = kh;
                if (kh->data.line_id == line_id && kh->data.station_id == station_id)
                {
                    data->sline.remove(count);
                    a[0] = 0;
                    pOutput = a;
                    N = 1;
                    return;
                }
                kh = kh->pNext;
                count++;
            }
        }
        a[0] = -1;
        pOutput = a;
        N = 1;
        return;
    }
    else
    {
        pOutput = nullptr;
        N = 0;
    }
}
