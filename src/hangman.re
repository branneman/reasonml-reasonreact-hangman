/**
 * Data
 */
let wordList = [
  "react",
  "reasonml",
  "rotterdam"
];
let hangmanTemplate = [
  "       \n       \n       \n       \n       \n       \n         ",
  "       \n       \n       \n       \n       \n       \n=========",
  "       \n      |\n      |\n      |\n      |\n      |\n=========",
  "  +---+\n      |\n      |\n      |\n      |\n      |\n=========",
  "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
  "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
  "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
  "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
  "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
  "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
  "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========",
];

/**
 * Hangman functions
 */
let getErrorLetters = (word) =>
  List.filter((letter) =>
    !String.contains(word, letter));
let getConstructedWord = (word) =>
  (letters) =>
    String.map((wc) =>
      List.exists((lc) => wc === lc, letters) ? wc : '_',
      word
    );

/**
 * Component
 */
type action =
  | Letter;

type state = {
  word: string,
  letters: list(char)
};

let component = ReasonReact.reducerComponent("Hangman");

let make = (_children) => {

  ...component,

  initialState: () => {
    word: "reasonml",
    letters: ['q', 'z']
  },

  reducer: (action, state) =>
    switch action {
      | Letter => ReasonReact.Update({...state, letters: ['a', ...state.letters]})
    },

  render: (self) => {
    let str = ReasonReact.stringToElement;
    <div>
      <div className="hangman hangman--shadow">
        (str(List.nth(hangmanTemplate, 10)))
      </div>
      <div className="hangman">
        (str(List.nth(hangmanTemplate, 2)))
      </div>
      <div className="word">(str(self.state.word))</div>
      <div className="letters">(str(""))</div>
    </div>
  }

};
