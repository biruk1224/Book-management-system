#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<iomanip>
using namespace std;
string Title,Author,Publisher,Date_of_pub;
int No_of_pages,No_of_books,ISBn;


struct Book{
string title;
string author;
string publisher;
string date_of_pub;
int no_of_pages;
int no_of_books;
int ISBN;
Book *next;
Book *prev;
};

void insert_in_sorted_ISBN(string,string,string,string,int,int,int);
void insert_in_sorted_title(string,string,string,string,int,int,int);
void get_info();
void add_begin(string,string,string,string,int,int,int);
void add_end(string,string,string,string,int,int,int);
void update(string);
void Remove(string);
void SearchTITLE(string);
void search_ISBN(int);
void search_author(string);
void display();
Book *head=NULL;
int main(){

         int ch;
   while(1){
        cout<<"                      ..................................BOOK STOCK..................................\n";
  cout<<"                           press 1 to add book at the begining\n";
  cout<<"                           press 2 to add book at the end \n";
  cout<<"                           press 3 to add book at any position in sorted list using title\n";
  cout<<"                           press 4 to add book at any postion in sorted list using ISBN\n";
  cout<<"                           press 5 to update book info\n";
  cout<<"                           press 6 to remove book from the stock\n";
  cout<<"                           press 7 to Search with TITLE of a book\n";
  cout<<"                           press 8 to Search with ISBN of a book\n";
  cout<<"                           press 9 to Search with AUTHOR of a book\n";
  cout<<"                           press 10 to display the books info\n";
  cout<<"                           press -1 to quit"<<endl;
cin>>ch; // the user choice to enter




switch(ch)
{
  case 1:
cin.ignore();
get_info();

add_begin(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
    break;

  case 2:
cin.ignore();
get_info();
add_end(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
break;
  case 3:
      cin.ignore();
    get_info();
    insert_in_sorted_title(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
      break;
  case 4:
    cin.ignore();
    get_info();
    insert_in_sorted_ISBN(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);

      break;
  case 5:
      cout<<"enter the title"<<endl;
      cin.ignore();
getline(cin,Title);
update(Title);
        break;
  case 6:
    cout<<"enter the title of the book u want to remove:"<<endl;
    cin.ignore();
    getline(cin,Title);
    Remove(Title);
    break;
  case 7:
    cout<<"enter the title of the book you want to search"<<endl;
    cin.ignore();
    getline(cin,Title);
    SearchTITLE(Title);
    break;
  case 8:
    cout<<"enter the ISBN of the book you want to search"<<endl;
    cin>>ISBn;
    search_ISBN(ISBn);
    break;
  case 9:
    cout<<"enter the author you want to search "<<endl;
    cin.ignore();
    getline(cin,Author);
    search_author(Author);
    break;
  case 10:
    display();
        break;
  case -1 :
    exit(1);//quit if user enter -1
  default :
    cout<<"invalid choice"<<endl;


}
   }

return 0;
}
void add_begin(string t,string a,string p,string d,int n,int nb,int e){

 Book *temp=new Book; //creating a new memory adress of structure
    if(temp==NULL)
    {
        cout<<"Sorry, Memory full!";
        return;
    }
    temp->title=t;
    temp->author=a;
    temp->publisher=p;
    temp->date_of_pub=d;
    temp->no_of_pages=n;
    temp->no_of_books=nb;
    temp->ISBN=e;
    temp->prev=NULL;
    temp->next=head;
    if(head!=NULL)
    {
        head->prev=temp;
    }
    head=temp;
}
void display()
{
    Book *temp;
    if(head==NULL)
    {
        cout<<"\n No Book left in the stock!";
        return;
    }
    cout<<"\nHERE ARE THE BOOKS IN STOCK\n";
    temp=head;
    while(temp!=NULL)//traverse until the last Book
    {

        cout<<setiosflags(ios::left)<<setw(20);
        cout<<"TITLE  "<<temp->title<<"\n";
        cout<<setiosflags(ios::left)<<setw(20);

        cout<<"AUTHOR "<<temp->author<<"\n";
        cout<<setiosflags(ios::left)<<setw(20);
        cout<<"PUBLISHER "<<temp->publisher<<"\n";
        cout<<setiosflags(ios::left)<<setw(20);
        cout<<"PUBLISHING DATE "<<temp->date_of_pub<<"\n";
        cout<<setiosflags(ios::left)<<setw(20);
        cout<<"NO_OF_PAGES "<<temp->no_of_pages<<"\n";
        cout<<setiosflags(ios::left)<<setw(20);
        cout<<"NO OF BOOkS LEFT "<<temp->no_of_books<<"\n";
        cout<<setiosflags(ios::left)<<setw(20);
        cout<<"ISBN OF THE BOOK :"<<temp->ISBN<<"\n";
cout<<"\n\n\n";
        temp=temp->next;
    }
}
void add_end(string t,string a,string p,string d,int n,int nb,int e)
{ Book *temp=new Book;

    temp->title=t;
    temp->author=a;
    temp->publisher=p;
    temp->date_of_pub=d;
    temp->no_of_pages=n;
    temp->no_of_books=nb;
    temp->ISBN=e;
    temp->prev=NULL;
    temp->next=head;
   if(head==NULL){
    head=temp;
   }
else{
    Book *temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }

    temp1->next=temp;
    temp->prev=temp1;
    temp->next=NULL;
}

}


void SearchTITLE(string t){//searching by title
    Book *temp=head;
int c=0;
    if(head==NULL){
        cout<<"no book in the stock"<<endl;
        return;
    }


else{
    while(temp->title!=t&&temp->next!=NULL){
        temp=temp->next;
        c++;//find the location
    }

if(temp->title==t){
    cout<<"the book is found at index  "<<c<<endl;
    return;}
    else
        cout<<"the book is not found"<<endl;
}
}




void search_author(string a){//searching by author
    Book *temp=head;
int c=0;
    if(head==NULL){
        cout<<"no book in the stock"<<endl;
        return;
    }


else{
    while(temp->author!=a&&temp->next!=NULL){
        temp=temp->next;
        c++;//find the location
    }
if(temp->author==a)
    cout<<"the book is found at index  "<<c<<endl;
    else  cout<<"book not found"<<endl;
}
}

void search_ISBN(int I){//searching by ISBN
    Book *temp=head;
int c=0;
    if(head==NULL){
        cout<<"no book in the stock"<<endl;
        return;
    }


else{
    while(temp->ISBN!=I&&temp->next!=NULL){
        temp=temp->next;
        c++;//find the location
    }
if(temp->ISBN==I)
    cout<<"the book is found at index  "<<c<<endl;
    else cout<<"book is not found"<<endl;
}
}


void get_info(){ //reads info from the Labrarian


cout<<"enter the title of the book"<<endl;
getline(cin,Title);
cout<<"\nenter the author of the book"<<endl;
getline(cin,Author);
cout<<"\nenter the publisher of the book"<<endl;
getline(cin,Publisher);
cout<<"enter the publisher date:"<<endl;
getline(cin,Date_of_pub);
cout<<"enter the no of pages of the book"<<endl;
cin>>No_of_pages;
cout<<"enter the no of the book left in the stock"<<endl;
cin>>No_of_books;
cout<<"enter the ISBN of the book"<<endl;
cin>>ISBn;

}
void update(string Title){//updating the no of books if it sold

Book *temp=head;
if(head==NULL){
    cout<<"there is no book with this title"<<endl;
return;
}
while(temp->title!=Title){
    temp=temp->next;
}
temp->no_of_books--;
}
void insert_in_sorted_title(string Title,string Author,string Publisher,string Date_of_pub,int No_of_pages,
                      int No_of_books,int ISBn)
 {
     Book*temp=new Book;
     if(temp==NULL)
     {
         cout<<"No enough memory!";
     }
     else if (head==NULL)
        add_begin(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
     else
     {
    temp->title=Title;
    temp->author=Author;
    temp->publisher=Publisher;
    temp->date_of_pub=Date_of_pub;
    temp->no_of_pages=No_of_pages;
    temp->no_of_books=No_of_books;
    temp->ISBN=ISBn;
    temp->prev=NULL;
         Book*curr=head;
         Book*pre;
         while(curr!=NULL&&curr->title<Title)
         {
             pre=curr;
             curr=curr->next;
         }
         if(curr==head)
         {
             add_begin(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
         }
         else if(curr==NULL)
         {
             add_end(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
         }
         else
         {
             temp->next=pre->next;
             pre->next=temp;
         }

     }
 }
void insert_in_sorted_ISBN(string Title,string Author,string Publisher,string Date_of_pub,int No_of_pages,
                      int No_of_books,int ISBn)
 {
     Book*temp=new Book;
     if(temp==NULL)
     {
         cout<<"No enough memory!";
     }
     else if (head==NULL)
        add_begin(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
     else
     {
    temp->title=Title;
    temp->author=Author;
    temp->publisher=Publisher;
    temp->date_of_pub=Date_of_pub;
    temp->no_of_pages=No_of_pages;
    temp->no_of_books=No_of_books;
    temp->ISBN=ISBn;
    temp->prev=NULL;
         Book*curr=head;
         Book*pre;
         while(curr!=NULL&&curr->ISBN<ISBn)
         {
             pre=curr;
             curr=curr->next;
         }
         if(curr==head)
         {
             add_begin(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
         }
         else if(curr==NULL)
         {
             add_end(Title,Author,Publisher,Date_of_pub,No_of_pages,No_of_books,ISBn);
         }
         else
         {
             temp->next=pre->next;
             pre->next=temp;
         }

     }
 }
void Remove(string t){
    Book *temp=head;
if(head->title==t){
    head=temp->next;
    delete temp;
}

else {

    while(temp->next->title!=t|| temp->next==NULL){
    temp=temp->next;

    }
    if(temp->next==NULL){
        cout<<"no book"<<endl;
        return;
    }

Book *temp1=temp->next;
 if(temp1->next==NULL){

    temp->next=NULL;
    delete temp1;
 }
else{
temp1->next->prev=temp;
temp->next=temp1->next;
delete temp1;}
}
}






