# Movie Rating Prediction

A machine learning project that predicts movie ratings based on various features including synopsis, genres, actors, and directors using XGBoost regression and sentence embeddings.

## 📁 Project Structure

```
Movie Rating Prediction/
│
├── app.ipynb              # Jupyter notebook with data collection and model training
├── app.py                 # Streamlit web application
├── movies_dataset.csv     # Generated dataset from TMDB API
├── movie_rating_model.pkl # Trained XGBoost model
├── sentence_model.pkl     # Sentence transformer model
├── genre_columns.pkl      # Genre columns for one-hot encoding
├── avg_actor_rating.pkl   # Average ratings by actor
├── avg_director_rating.pkl # Average ratings by director
└── additional.py          # API key configuration
```

## 🎯 Features

- **Data Collection**: Automatically fetches movie data from The Movie Database (TMDB) API
- **Feature Engineering**: 
  - Synopsis embeddings using SentenceTransformer
  - Genre one-hot encoding
  - Actor and director average ratings
- **Machine Learning**: XGBoost regression model for rating prediction
- **Web Interface**: Interactive Streamlit application for predictions

## 🔧 Installation

1. **Clone the repository**:
   ```bash
   git https://github.com/shuvomdhar/Projects.git
   ```
   ```bash
   cd "Movie Rating Prediction"
   ```

2. **Install required packages**:
   ```bash
   pip install numpy pandas scikit-learn xgboost sentence-transformers streamlit requests pickle
   ```

3. **Set up TMDB API key**:
   - Create an account at [The Movie Database](https://www.themoviedb.org/)
   - Get your API key from the API settings of your account

## 🚀 Usage

### Training the Model

1. **Run the Jupyter notebook** (`app.ipynb`):
   - Execute all cells to fetch data and train the model
   - The notebook will generate the dataset and save trained models

2. **Key steps in training**:
   - Fetches popular movies data from TMDB API
   - Processes movie details including cast, crew, and metadata
   - Creates sentence embeddings for movie synopses
   - Trains XGBoost regression model
   - Saves all necessary model files

### Running the Web Application

1. **Start the Streamlit app**:
   ```bash
   streamlit run app.py
   ```

2. **Use the interface**:
   - Enter actors (comma-separated)
   - Enter director name
   - Enter genres (comma-separated)
   - Enter movie synopsis
   - Click "Predict Rating" to get the predicted rating

## 📊 Model Performance

- **R² Score**: 0.9354
- **Mean Squared Error**: 0.0401

The model demonstrates excellent performance with high R² score indicating strong predictive capability.

## 🔍 Model Features

1. **Synopsis Embeddings**: 
   - Uses `all-MiniLM-L6-v2` SentenceTransformer model
   - Converts text synopsis to numerical vectors

2. **Genre Encoding**: 
   - One-hot encoding for movie genres
   - Supports multiple genres per movie

3. **Actor/Director Ratings**: 
   - Historical average ratings for actors and directors
   - Fallback to overall mean for unknown actors/directors

4. **XGBoost Configuration**:
   - 300 estimators
   - Learning rate: 0.03
   - Max depth: 7
   - Subsample: 0.8
   - Column sample: 0.8

## 📝 Data Source

The project uses [The Movie Database (TMDB) API](https://www.themoviedb.org/documentation/api) to fetch:
- Movie titles and overviews
- Genre information
- Cast and crew details
- User ratings (vote_average)

## 🛠️ Technical Details

### Data Processing Pipeline:
1. **API Data Fetching**: Retrieves popular movies from TMDB
2. **Feature Extraction**: Processes text and categorical data
3. **Embedding Generation**: Creates numerical representations
4. **Model Training**: Fits XGBoost regression model
5. **Model Serialization**: Saves trained models for deployment

### Key Libraries:
- **pandas**: Data manipulation and analysis
- **numpy**: Numerical computations
- **scikit-learn**: Machine learning utilities
- **xgboost**: Gradient boosting framework
- **sentence-transformers**: Text embedding generation
- **streamlit**: Web application framework
- **requests**: HTTP library for API calls

## 🚨 Important Notes

1. **API Limitations**: The TMDB API has rate limits - be mindful when fetching large datasets
2. **Model Files**: Ensure all `.pkl` files are present before running the Streamlit app
3. **Data Quality**: The model's performance depends on the quality and quantity of training data
4. **Genre Format**: Enter genres exactly as they appear in TMDB (e.g., "Action, Adventure, Drama")

## 🔮 Future Enhancements

- Add more features like budget, runtime, and release date
- Implement ensemble methods for better predictions
- Add support for multiple languages
- Include box office performance prediction
- Enhance UI with better visualization and movie posters

## 📄 License

This project is for educational and commercial use. Please review applicable data privacy regulations before deployment.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request or open an Issue for bugs and feature requests.