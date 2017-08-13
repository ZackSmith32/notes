# I like cards. Model for me a deck of cards.

# A deck consists of cards, and each card should have a
# - value: 1...13
# - suit: 'clubs', 'hearts', 'spades', 'diamonds'
# - name: e.g. '2 of hearts', 'ace of spades'

# The deck should come with the following functions:
# - a function that returns the cards remaining in the deck
# - a function that returns the card at the top of the deck, and removes it from the deck
# - a function that randomizes the order of the cards

#EXTENSIONS

# - How would you handle or avoid irregular cards from being entered?
# - Does your shuffle function emulate shuffling like how we would practically do it in real life? How would you emulate that?
# - I sometimes have friends over and we like to play cards together. Can you update your code to deal n number of hands?

import random


card_mapping = { 1: "ace", 11: "jack", 12: "queen", 13: "king"}


class CardDeck():
    
    def __init__(self):
        self.deck = []
        for i in range(1, 14):
            for suit in ('clubs', 'hearts', 'spades', 'diamonds'):
                if i in card_mapping:
                    self.deck.append(Card(card_mapping[i], suit))
                else:
                    self.deck.append(Card(i, suit))
        
    def print_deck(self):
        for card in self.deck:
            card.print_card()
    
    def get_deck(self):
        return (self.deck)
    
    def pop_top(self):
        return (self.deck.pop())
    
    def shuffle(self):
        random.shuffle(self.deck)
    
    def dec_len(self):
        return (len(self.deck))
    
class Card():
    
    def __init__(self, number, suit):
        self.number = number
        self.suit = suit
        
    def print_card(self):
        print(self.number, "of", self.suit)
        
        
def main():
    
    deck = CardDeck()
    #deck.print_deck()
    deck.pop_top().print_card()
    print("deck len:")
    print(deck.dec_len())
    
    print("\n\ntest shuffle")
    deck.shuffle()
    #deck.print_deck()
    for card in deck.get_deck():
        card.print_card()
    
       
    
if __name__ == "__main__":
    main()
    

    # jng@blend.com
    # mzhang@blend.com