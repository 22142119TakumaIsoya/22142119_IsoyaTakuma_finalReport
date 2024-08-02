#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <map>

using namespace std;

int main1() {
    cout << "日本代表ロスター" << endl;
    cout << "背番号,氏名,ポジション,所属チーム" << endl;
    cout << "2,富樫 勇樹,PG,千葉ジェッツ\n4,ジェイコブス 晶,SF,ハワイ大学\n5,河村 勇輝,PG,横浜ビー・コルセアーズ\n";
    cout << "6,比江島 慎,SG,宇都宮ブレックス\n7,テーブス 海,PG,アルバルク東京\n8,八村 塁,PF,ロサンゼルス・レイカーズ\n";
    cout << "12,渡邊 雄太,SF,千葉ジェッツ\n18,馬場 雄大,SF,長崎ヴェルカ\n";
    cout << "24,ジョシュ・ホーキンソン,C,サンロッカーズ渋谷\n30,富永 啓生,SG,ネブラスカ大学\n34,渡邉 飛勇,C,カリフォルニア大学\n";
    cout << "91,吉井 裕鷹,SF,三遠ネオフェニックス\n" << endl;
    return 0;
}

class Player {
public:
    string name;
    int number;
    string team;
    string position;

    Player() {}
    Player(const string& name, int number, const string& team, const string& position)
        : name(name), number(number), team(team), position(position) {}
};

class Match {
public:
    string opponent;
    string date;

    Match(const string& opponent, const string& date)
        : opponent(opponent), date(date) {}
};

// 選手のデータを定義
map<int, Player> numberPlayers = {
    {2, {"富樫 勇樹", 2, "千葉ジェッツ", "PG"}},
    {4, {"ジェイコブス 晶", 4, "ハワイ大学", "SF"}},
    {5, {"河村 勇輝", 5, "横浜ビー・コルセアーズ", "PG"}},
    {6, {"比江島 慎", 6, "宇都宮ブレックス", "SG"}},
    {7, {"テーブス 海", 7, "アルバルク東京", "PG"}},
    {8, {"八村 塁", 8, "ロサンゼルス・レイカーズ", "PF"}},
    {12, {"渡邊 雄太", 12, "千葉ジェッツ", "SF"}},
    {18, {"馬場 雄大", 18, "長崎ヴェルカ", "SF"}},
    {24, {"ジョシュ・ホーキンソン", 24, "サンロッカーズ渋谷", "C"}},
    {30, {"富永 啓生", 30, "ネブラスカ大学", "SG"}},
    {34, {"渡邉 飛勇", 34, "カリフォルニア大学", "C"}},
    {91, {"吉井 裕鷹", 91, "三遠ネオフェニックス", "SF"}}
};

// 選手の追加関数
void addPlayer(vector<Player>& team) {
    int number;

    cout << "スターティングメンバーの背番号を入力: ";
    cin >> number;

    auto it =numberPlayers.find(number);
    if (it !=numberPlayers.end()) {
        team.push_back(it->second);
        cout << "選手を追加しました: " << it->second.name << " (" << it->second.position << ", " << it->second.team << ")\n";
    }
    else {
        cerr << "選手が見つかりませんでした\n";
    }
}

// 選手の削除
void removePlayer(vector<Player>& team) {
    int number;
    bool playerFound = false;

    cout << "削除したい選手の背番号を入力: ";
    cin >> number;

    for (auto it = team.begin(); it != team.end(); ++it) {
        if (it->number == number) {
            team.erase(it);
            playerFound = true;
            cout << "選手を削除しました\n";
            break;
        }
    }

    if (!playerFound) {
        cerr << "選手が見つかりませんでした\n";
    }
}

// 選手の編集
void editPlayer(vector<Player>& team) {
    int number;
    string newName, newTeam, newPosition;
    bool playerFound = false;

    cout << "編集したい選手の背番号を入力: ";
    cin >> number;

    for (auto& player : team) {
        if (player.number == number) {
            cout << "新しい選手の名前を入力: ";
            cin >> newName;
            cout << "新しいポジションを入力: ";
            cin >> newPosition;
            cout << "新しい所属チームを入力: ";
            cin >> newTeam;

            player.name = newName;
            player.position = newPosition;
            player.team = newTeam;
            playerFound = true;
            cout << "選手のデータを変更しました\n";
            break;
        }
    }

    if (!playerFound) {
        cerr << "選手が見つかりませんでした\n";
    }
}

// 選手の表示
void displayPlayers(const vector<Player>& team) {
    cout << "スターティングメンバー:\n";
    for (const auto& player : team) {
        cout << "Number: " << player.number << ", Name: " << player.name << ", Team: " << player.team << ", Position: " << player.position << endl;
    }
}

// 試合の追加
void addMatch(vector<Match>& schedule) {
    string opponent, date;

    cout << "対戦相手: ";
    cin >> opponent;
    cout << "日程: ";
    cin >> date;

    schedule.emplace_back(opponent, date);
}

// 試合の表示
void displayMatches(const vector<Match>& schedule) {
    cout << "試合日程:\n";
    for (const auto& match : schedule) {
        cout << "対戦相手: " << match.opponent << ", 日程: " << match.date << endl;
    }
}

int main2() {
    vector<Player> team;
    vector<Match> schedule;
    int choice;

    do {
        cout << "1: 選手登録\n2: 登録抹消\n3: 選手の編集\n4: 選手を表示\n";
        cout << "5: 試合を追加\n6: 試合を表示\n7: 終了\n \n1～7を選択してください: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
                addPlayer(team);
                break;
            case 2:
                removePlayer(team);
                break;
            case 3:
                editPlayer(team);
                break;
            case 4:
                displayPlayers(team);
                break;
            case 5:
                addMatch(schedule);
                break;
            case 6:
                displayMatches(schedule);
                break;
            case 7:
                cout << "終了しました\n";
                break;
            default:
                cerr << "正しく入力してください\n";
            }
        }
        catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != 7);

    return 0;
}

int main() {
    main1();
    return main2();
}