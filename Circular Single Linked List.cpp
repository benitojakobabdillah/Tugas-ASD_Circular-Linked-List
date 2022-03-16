#include <iostream>
using namespace std;
struct helm{
  string mrk, jns, hrg;

  helm *next;
};

helm *head, *tail, *newNode, *cur, *del;

void createCircularSingleLinkedList(string newinfo[3]){

  head = new helm();
  head->mrk = newinfo[0];
  head->jns = newinfo[1];
  head->hrg = newinfo[2];
  tail = head;
  tail->next = head;

}

void addFirst( string info[3] ){
  if( head == NULL ){
    cout << "Linked List Tidak Ada" << endl;
  }else{
    newNode = new helm();
    newNode->mrk = info[0];
    newNode->jns = info[1];
    newNode->hrg = info[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast( string info[3] ){
  if( head == NULL ){
    cout << "Linked List Tidak Ada" << endl;
  }else{
    newNode = new helm();
    newNode->mrk = info[0];
    newNode->jns = info[1];
    newNode->hrg = info[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string info[3], int kordinat)
{
  if( head == NULL ){
    cout << "Linked List Tidak Ada" << endl;
  }else{
    if( kordinat == 1 ){
      cout << "Kordinat satu tidak ditengah" << endl;
    }else{
      newNode = new helm();
      newNode->mrk = info[0];
      newNode->jns = info[1];
      newNode->hrg = info[2];

      int nomor = 1;
      cur = head;
      while (nomor < kordinat - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void removeFirst(){
  if( head == NULL ){
    cout << "Linked List Tidak Ada" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

void removeLast()
{
  if( head == NULL ){
    cout << "Linked List Tidak Ada" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

void removeMiddle(int kordinat)
{
  if( head == NULL ){
    cout << "Linked List Tidak Ada" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while( nomor < kordinat - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}

void printCircular()
{
  if( head == NULL ){
    cout << "Linked List Tidak Ada" << endl;
  }else{
    cout << " Daftar Helm " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| Merek\t\t| Jenis\t\t\t| Harga\t\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while (cur->next != head)
    {
      cout << "| " << cur->mrk << "\t| " << cur->jns << "\t| " << cur->hrg << "\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->mrk << "\t| " << cur->jns << "\t| " << cur->hrg << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}

int main(){
  string newinfo[3] = {"Shark", "GP Helmet", "50000000"};
  createCircularSingleLinkedList(newinfo);

  printCircular();

  string info[3] = {"AGV", "Racing Helmet", "40000000"};
  addFirst(info);

  printCircular();

  string info2[3] = {"KYT", "Slowride Helmet", "1000000"};
  addLast(info2);

  printCircular();

  string info3[3] = {"Arai", "Antique Helmet", "100000000"};
  addMiddle(info3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}