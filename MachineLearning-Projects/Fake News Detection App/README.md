# Fake News Detection App

A machine learning application that detects fake news articles using logistic regression. The application features a Streamlit web interface for real-time news classification.

## Project Structure

```
Fake News Detection App/
│
├── app.py                # Streamlit web application
├── app.ipynb            # Jupyter notebook with ML model training code
├── Fake.csv             # Dataset containing fake news articles
├── True.csv             # Dataset containing true news articles
├── lr_model.jb          # Trained logistic regression model (joblib format)
├── vectorizer.jb        # Fitted vectorizer (joblib format)
└── requirement.txt      # Package dependencies
```

## Features

- **Machine Learning Model**: Logistic regression classifier for binary classification
- **Pre-trained Model**: Ready-to-use trained model and vectorizer
- **Interactive Web Interface**: Streamlit-based UI for easy testing
- **Real-time Prediction**: Instant classification of news articles as real or fake
- **Dual Dataset**: Separate CSV files for fake and true news articles

## Requirements

Check `requirement.txt` for the complete list of dependencies. Key packages include:
- streamlit
- pandas
- numpy
- scikit-learn
- joblib

## Installation

1. **Navigate to the project folder**:
   ```bash
   cd "Fake News Detection App"
   ```

2. **Install required packages**:
   ```bash
   pip install -r requirement.txt
   ```

## Usage

### Running the Application

Start the Streamlit application with:

```bash
streamlit run app.py
```

The application will open in your default web browser, typically at `http://localhost:8501`.

### Using the Interface

1. **Enter News Text**: Input the news article content you want to analyze
2. **Get Prediction**: The app will classify the text as either "Real" or "Fake"
3. **View Results**: See the classification result with confidence indicators

## Dataset Information

The project uses two separate CSV files:

- **`Fake.csv`**: Contains fake news articles for training
- **`True.csv`**: Contains legitimate news articles for training

These datasets are used in the Jupyter notebook (`app.ipynb`) to train the logistic regression model.

## Model Details

### Training Process
- **Notebook**: All machine learning code is implemented in `app.ipynb`
- **Algorithm**: Logistic regression for binary classification
- **Data Processing**: Basic text processing without advanced NLP techniques
- **Output**: Trained model saved as `lr_model.jb` and vectorizer as `vectorizer.jb`

### Model Files
- **`lr_model.jb`**: Serialized logistic regression model using joblib
- **`vectorizer.jb`**: Fitted text vectorizer for preprocessing input text

## Development Workflow

1. **Data Exploration & Training**: Open and run `app.ipynb` to:
   - Load data from `Fake.csv` and `True.csv`
   - Train the logistic regression model
   - Save the trained model and vectorizer

2. **Application Deployment**: Run `app.py` to:
   - Load the pre-trained model (`lr_model.jb`)
   - Load the fitted vectorizer (`vectorizer.jb`)
   - Provide web interface for predictions

## Retraining the Model

To retrain the model with updated data:

1. **Update the datasets**: Modify `Fake.csv` and/or `True.csv` with new data
2. **Run the notebook**: Execute all cells in `app.ipynb`
3. **New model files**: Updated `lr_model.jb` and `vectorizer.jb` will be generated
4. **Restart the app**: Run `streamlit run app.py` to use the updated model

## File Dependencies

- **`app.py`** depends on:
  - `lr_model.jb` (trained model)
  - `vectorizer.jb` (fitted vectorizer)
  - Packages listed in `requirement.txt`

- **`app.ipynb`** depends on:
  - `Fake.csv` (fake news dataset)
  - `True.csv` (true news dataset)
  - Packages listed in `requirement.txt`

## Technical Implementation

### Model Training (app.ipynb)
- Loads data from CSV files
- Combines fake and true news datasets
- Trains logistic regression classifier
- Saves model and vectorizer using joblib

### Prediction App (app.py)
- Loads pre-trained model and vectorizer
- Provides Streamlit interface
- Processes user input and returns predictions
- No complex NLP preprocessing required

## Quick Start

1. Ensure all files are in the "Fake News Detection App" folder
2. Install dependencies: `pip install -r requirement.txt`
3. Run the app: `streamlit run app.py`
4. Open your browser and start testing!

## Troubleshooting

**Common Issues:**
- **Missing model files**: Run `app.ipynb` first to generate `lr_model.jb` and `vectorizer.jb`
- **Package errors**: Ensure all packages in `requirement.txt` are installed
- **File path issues**: Make sure you're running commands from within the project folder

## Notes

- The model uses basic text processing without advanced NLP techniques
- All machine learning logic is contained in the Jupyter notebook
- The Streamlit app focuses on providing a user-friendly interface
- Model and vectorizer are saved in joblib format for efficient loading

## License

This project is for educational and demonstration purposes.

---

**Usage**: Simply run `streamlit run app.py` to start the application and begin detecting fake news!