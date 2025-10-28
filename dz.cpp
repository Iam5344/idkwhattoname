#include <iostream>
#include <string>
using namespace std;

class Audio {
public:
    virtual void Play() = 0;
    virtual ~Audio() {}
};

class Song : public Audio {
private:
    string title;
    string artist;
    
public:
    Song(string t, string a) {
        title = t;
        artist = a;
    }
    
    void Play() override {
        cout << "Playing song: " << title << " by " << artist << endl;
    }
};

class Podcast : public Audio {
private:
    string host;
    string topic;
    
public:
    Podcast(string h, string t) {
        host = h;
        topic = t;
    }
    
    void Play() override {
        cout << "Podcast on " << topic << " hosted by " << host << endl;
    }
};

class Audiobook : public Audio {
private:
    string bookTitle;
    string author;
    string voice;
    
public:
    Audiobook(string bt, string a, string v) {
        bookTitle = bt;
        author = a;
        voice = v;
    }
    
    void Play() override {
        cout << "Listening to audiobook: " << bookTitle << " by " << author << ". Read by " << voice << "." << endl;
    }
};

int main() {
    setlocale(0, "");
    
    int choice;
    Audio* audio = nullptr;
    
    cout << "Выберите тип аудио:" << endl;
    cout << "1. Песня" << endl;
    cout << "2. Подкаст" << endl;
    cout << "3. Аудиокнига" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        string title, artist;
        cout << "Введите название песни: ";
        getline(cin, title);
        cout << "Введите исполнителя: ";
        getline(cin, artist);
        audio = new Song(title, artist);
    } 
    else if (choice == 2) {
        string host, topic;
        cout << "Введите тему подкаста: ";
        getline(cin, topic);
        cout << "Введите ведущего: ";
        getline(cin, host);
        audio = new Podcast(host, topic);
    } 
    else if (choice == 3) {
        string bookTitle, author, voice;
        cout << "Введите название книги: ";
        getline(cin, bookTitle);
        cout << "Введите автора: ";
        getline(cin, author);
        cout << "Введите чтеца: ";
        getline(cin, voice);
        audio = new Audiobook(bookTitle, author, voice);
    }
    
    if (audio != nullptr) {
        audio->Play();
        delete audio;
    }
    
    return 0;
}
