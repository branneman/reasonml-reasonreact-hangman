Random.self_init();

/**
 * Data
 */
let wordList = [
  "awesomeness",
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
 * Utils
 */
let join = (str, list) => String.concat(str, List.map(String.make(1), list));
let str = ReasonReact.stringToElement;

/**
 * Hangman functions
 */
let getErrorLetters = (word) =>
  List.filter((letter) =>
    !String.contains(word, letter));
let getConstructedWord = (word) =>
  (letters) =>
    String.map((wc) =>
      List.exists((lc) => wc === lc, letters) ? wc : '.',
      word
    );

/**
 * Component: Hangman
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
    word: List.nth(wordList, Random.int(List.length(wordList))),
    letters: ['r', 'e', 't', 'q']
  },

  reducer: (action, state) =>
    switch action {
      | Letter => ReasonReact.Update({...state, letters: ['a', ...state.letters]})
    },

  render: (self) => {

    let errorLetters = getErrorLetters(self.state.word, self.state.letters);
    let constructedWord = getConstructedWord(self.state.word, self.state.letters);

    <div>
      <div className="hangman hangman--shadow">
        (str(List.nth(hangmanTemplate, 10)))
      </div>
      <div className="hangman">
        (str(List.nth(hangmanTemplate, List.length(errorLetters))))
        <div className="word">(str(constructedWord))</div>
      </div>
      <div className="letters">(str(join("\n", errorLetters)))</div>
    </div>

  }

};
