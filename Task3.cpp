#include <iostream>
#include <vector>

using namespace std;

class Card {
	
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	//friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	int GetValue() const;

	void Flip();

	rank GetRank() {
		return m_Rank;
	};

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetValue() const {
	int value = 0;
	if (m_IsFaceUp) value = m_Rank;
	return value;
}

void Card::Flip() {
	m_IsFaceUp = !(m_IsFaceUp);
}

//=====Exercise 3==================================================================================

class Hand {
private:
	vector<Card*> HandCards;
public:
	void Add(Card* c) {
		HandCards.push_back(c);
	}

	void Clear() {
		HandCards.clear();
	}

	int GetValue() {
		int value = 0;
		bool haveace = false;
		for (size_t i = 0; i < HandCards.size(); i++)
		{		
			if (HandCards[i]->GetRank() == Card::ACE) haveace = true;
			value += HandCards[i]->GetValue();
		}		
		if (haveace && value <= 11) value += 10;
		return value;
	}
};

//=================================================================================================

int main()
{
	Hand hand;
	Card card1(Card::FIVE, Card::DIAMONDS,true);
	Card card2(Card::SEVEN, Card::HEARTS, true);
	Card card3(Card::ACE, Card::SPADES, true);
	hand.Add(&card1);
	hand.Add(&card2);
	hand.Add(&card3);
	cout << hand.GetValue() << endl;
	hand.Clear();
	cout << hand.GetValue() << endl;
}
