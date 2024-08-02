#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <map>

using namespace std;

int main1() {
    cout << "���{��\���X�^�[" << endl;
    cout << "�w�ԍ�,����,�|�W�V����,�����`�[��" << endl;
    cout << "2,�x�~ �E��,PG,��t�W�F�b�c\n4,�W�F�C�R�u�X ��,SF,�n���C��w\n5,�͑� �E�P,PG,���l�r�[�E�R���Z�A�[�Y\n";
    cout << "6,��]�� �T,SG,�F�s�{�u���b�N�X\n7,�e�[�u�X �C,PG,�A���o���N����\n8,���� ��,PF,���T���[���X�E���C�J�[�Y\n";
    cout << "12,�n� �Y��,SF,��t�W�F�b�c\n18,�n�� �Y��,SF,���胔�F���J\n";
    cout << "24,�W���V���E�z�[�L���\��,C,�T�����b�J�[�Y�a�J\n30,�x�i �[��,SG,�l�u���X�J��w\n34,�n� ��E,C,�J���t�H���j�A��w\n";
    cout << "91,�g�� �T��,SF,�O���l�I�t�F�j�b�N�X\n" << endl;
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

// �I��̃f�[�^���`
map<int, Player> numberPlayers = {
    {2, {"�x�~ �E��", 2, "��t�W�F�b�c", "PG"}},
    {4, {"�W�F�C�R�u�X ��", 4, "�n���C��w", "SF"}},
    {5, {"�͑� �E�P", 5, "���l�r�[�E�R���Z�A�[�Y", "PG"}},
    {6, {"��]�� �T", 6, "�F�s�{�u���b�N�X", "SG"}},
    {7, {"�e�[�u�X �C", 7, "�A���o���N����", "PG"}},
    {8, {"���� ��", 8, "���T���[���X�E���C�J�[�Y", "PF"}},
    {12, {"�n� �Y��", 12, "��t�W�F�b�c", "SF"}},
    {18, {"�n�� �Y��", 18, "���胔�F���J", "SF"}},
    {24, {"�W���V���E�z�[�L���\��", 24, "�T�����b�J�[�Y�a�J", "C"}},
    {30, {"�x�i �[��", 30, "�l�u���X�J��w", "SG"}},
    {34, {"�n� ��E", 34, "�J���t�H���j�A��w", "C"}},
    {91, {"�g�� �T��", 91, "�O���l�I�t�F�j�b�N�X", "SF"}}
};

// �I��̒ǉ��֐�
void addPlayer(vector<Player>& team) {
    int number;

    cout << "�X�^�[�e�B���O�����o�[�̔w�ԍ������: ";
    cin >> number;

    auto it =numberPlayers.find(number);
    if (it !=numberPlayers.end()) {
        team.push_back(it->second);
        cout << "�I���ǉ����܂���: " << it->second.name << " (" << it->second.position << ", " << it->second.team << ")\n";
    }
    else {
        cerr << "�I�肪������܂���ł���\n";
    }
}

// �I��̍폜
void removePlayer(vector<Player>& team) {
    int number;
    bool playerFound = false;

    cout << "�폜�������I��̔w�ԍ������: ";
    cin >> number;

    for (auto it = team.begin(); it != team.end(); ++it) {
        if (it->number == number) {
            team.erase(it);
            playerFound = true;
            cout << "�I����폜���܂���\n";
            break;
        }
    }

    if (!playerFound) {
        cerr << "�I�肪������܂���ł���\n";
    }
}

// �I��̕ҏW
void editPlayer(vector<Player>& team) {
    int number;
    string newName, newTeam, newPosition;
    bool playerFound = false;

    cout << "�ҏW�������I��̔w�ԍ������: ";
    cin >> number;

    for (auto& player : team) {
        if (player.number == number) {
            cout << "�V�����I��̖��O�����: ";
            cin >> newName;
            cout << "�V�����|�W�V���������: ";
            cin >> newPosition;
            cout << "�V���������`�[�������: ";
            cin >> newTeam;

            player.name = newName;
            player.position = newPosition;
            player.team = newTeam;
            playerFound = true;
            cout << "�I��̃f�[�^��ύX���܂���\n";
            break;
        }
    }

    if (!playerFound) {
        cerr << "�I�肪������܂���ł���\n";
    }
}

// �I��̕\��
void displayPlayers(const vector<Player>& team) {
    cout << "�X�^�[�e�B���O�����o�[:\n";
    for (const auto& player : team) {
        cout << "Number: " << player.number << ", Name: " << player.name << ", Team: " << player.team << ", Position: " << player.position << endl;
    }
}

// �����̒ǉ�
void addMatch(vector<Match>& schedule) {
    string opponent, date;

    cout << "�ΐ푊��: ";
    cin >> opponent;
    cout << "����: ";
    cin >> date;

    schedule.emplace_back(opponent, date);
}

// �����̕\��
void displayMatches(const vector<Match>& schedule) {
    cout << "��������:\n";
    for (const auto& match : schedule) {
        cout << "�ΐ푊��: " << match.opponent << ", ����: " << match.date << endl;
    }
}

int main2() {
    vector<Player> team;
    vector<Match> schedule;
    int choice;

    do {
        cout << "1: �I��o�^\n2: �o�^����\n3: �I��̕ҏW\n4: �I���\��\n";
        cout << "5: ������ǉ�\n6: ������\��\n7: �I��\n \n1�`7��I�����Ă�������: ";
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
                cout << "�I�����܂���\n";
                break;
            default:
                cerr << "���������͂��Ă�������\n";
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