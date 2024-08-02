/*
• 各自でテーマを決めて自由にプログラムを作成せよ
• ただし、以下の条件を満たすこと
• C++を使用すること
• 独自のクラス、関数を定義し用いること
• イテレーターを使用すること
• 公開されている様々なライブラリを使用しても構わないレポートには以下を含むこと
• プログラムの名称
• プログラムの目的
• プログラムの概要
• プログラムの処理の流れ（フローチャートなど）
• 実行結果（スクリーンショットなど）
• 標準ライブラリ以外に使用したライブラリ、他人のコード（使用した場合）
• 他人のコードを改変し使用した場合は、その変更点
• 参考文献
• ソースコードのGithubリポジトリのURL
• 注）GitHub上で確認するのでソースコードはレポートに記載しなくてよい
*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main1() {
	cout << "ここに日本代表のリストを記入 " << endl;//分かりやすく
}

class Player {
	string name;
	int number;
	string team;
	string position;

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

//選手の追加関数
void addPlayer(vector<Player>& team) {
	string name, team, position;
	int number;

	cout << "選手名を入力";
	cin >> name;
	cout << "背番号を入力";
	cin >> number;
	cout << "所属チームを入力";
	cin >> team;
	cout << "ポジションを入力";
	cin >> position;

	team.emplace_back(name, number, team, position);
}

//選手の削除
void removePlayer(vector<Player>& team) {
	int number;
	bool playerFound = false;

	cout << "外したい選手の背番号を入力";
	cin >> number;

	for (auto it = team.begin(); it != team.end(); ++it) {
		if (it -> number == number) {
			team.erase(it);
			playerFound = true;
			cout << "選手の削除";
			break;
		}
	}

	//エラー処理
	if (!playerFound) {
		cerr << "選手が見つかりませんでした\n";
	}
}
void editPlayer(vector<Player>& team) {
	int number;
	string newName, newTeam, newPosition;
	bool playerFound = false;

	//選手番号の入力
	cout << "編集したい選手の背番号を入力";
	cin >> number;

	for (auto& player : team){
		if(player.number == number){
			cout << "新しい選手の名前を入力";
			cin >> newName;
			cout << "新しいポジションを入力";
			cin >> newPosition;

			player.name = newName;
			plyaer.position = newPosition;
			playerFound = true;
			cout << "選手のデータをアップデート\n";
			break;
		}
	}

	if (!playerFound) {
		cerr << "選手は見つかりませんでした\n";
	}
}
void displayPlayers(const vector<Player>& team) {
	cout << "Team Players";
	for (const auto& player : team) {
		cout << "Number: " << player.number << ",Name: " << player.name << "Team: " << player.team << "Position: " << player.position << endl;
	}
}
void addMatch(vector<Match>& schedule) {
	string opponent, date;

	cout << "対戦相手; ";
	cin >> opponent;
	cout << "日程: ";
	cin >> date;

	schedule.emplace_back(opponent, date);
}
void displayMatches(const vector<Match>& schedule) {
	cout << "Match schedule:\n";
	for (const auto& match : schedule) {
		cout << "Opponent: " << match.opponent << ", Date: " << match.date << endl;
	}
}


int main2() {
	vector<Player> team;
	vector<Match> schedule;
	int choice;

	do {
		cout << "1: Add player\n2: Remove player\n3: Edit player\n4: Display players\n";
		cout << "5: Add match\n6: Display matches\n7: Exit\nEnter your choice: ";
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
				std::cout << "Exiting...\n";
				break;
			default:
				std::cerr << "Invalid choice. Try again.\n";
			}
		}
		catch (const std::exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	} while (choice != 7);

	return 0;
}*/