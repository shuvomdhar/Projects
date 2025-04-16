# step 1 - import equired library
from spellchecker import SpellChecker

# step 2 - creating the app class
class SpellCheckerApp:
    def __init__(self):
        self.spell = SpellChecker()

    def correct_text(self, text):
        words = text.split()
        corrected_words = []
        
        for word in words:
            corrected_word = self.spell.correction(word)
            if corrected_word != word.lower():
                print(f'Corrected "{word}" to "{corrected_word}"')
                corrected_words.append(corrected_word)

        # step 3 - return the corrected text
        return ' '.join(corrected_words)
    
    # step 4 - running the app
    def run(self):
        print("\n---Spell Checker App---")

        while True:
            text = input("Enter a text to correct (or 'q' to quit): ")

            if text.lower() == 'q':
                print('Closing the app...')
                break
            
            corrected_text = self.correct_text(text)
            print(f'Corrected text: {corrected_text}\n')

# step 5 - running the app
if __name__ == "__main__":
    SpellCheckerApp().run()