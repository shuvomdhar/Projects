# Emotion Detection App

A machine learning-powered web application that analyzes text messages and predicts the underlying emotion expressed in the text. Built with TensorFlow/Keras for deep learning and Streamlit for the user interface.

## Features

- **Real-time Emotion Analysis**: Input any text message and get instant emotion predictions
- **Multiple Emotion Categories**: Detects various emotions such as joy, sadness, anger, fear, surprise, and more
- **Interactive Web Interface**: Clean and intuitive Streamlit-based UI
- **Confidence Scoring**: Shows prediction confidence levels for each detected emotion
- **Data Visualization**: Visual representation of emotion probabilities using matplotlib charts

## Technology Stack

- **TensorFlow/Keras**: Deep learning framework for building and training the emotion classification model
- **Streamlit**: Web application framework for creating the interactive user interface
- **imbalanced-learn (imblearn)**: Handles class imbalance in training data for better model performance
- **Matplotlib**: Data visualization for displaying emotion prediction results
- **Joblib**: Model serialization and loading for efficient deployment
- **Python**: Core programming language

## Installation

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd Emotion Detection
   ```

2. **Create a virtual environment**
   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows: venv\Scripts\activate
   ```

3. **Install required dependencies**
   ```bash
   pip install -r requirements.txt
   ```

## Usage

1. **Start the Streamlit application**
   ```bash
   streamlit run app.py
   ```

2. **Access the web interface**
   - Open your browser and navigate to `http://localhost:8501`
   - The application will load with a text input field

3. **Analyze emotions**
   - Enter your text message in the input field
   - Click the "Analyze Emotion" button
   - View the predicted emotion and confidence scores
   - See the visualization chart showing probability distribution

## Model Architecture

The emotion detection model uses a deep learning approach with the following components:

- **Text Preprocessing**: Tokenization, cleaning, and vectorization of input text
- **Neural Network**: Multi-layer architecture with embedding layers for text representation
- **Classification Layer**: Softmax activation for multi-class emotion prediction
- **Class Balancing**: imblearn techniques to handle imbalanced emotion datasets

## Supported Emotions

The model can detect the following emotions:

- Love
- Sadness
- Anger
- Fear

## File Structure

```
Emotion Detection/
├── app.py                 # Main Streamlit application
├── emotion_model.keras   # Trained Keras model
├── tokenizer.jb      # Saved tokenizer (joblib)
├── label_encoder.jb  # Saved label encoder (joblib)
├── emotion_dataset.csv  # Training dataset
├── app.ipynb # Jupyter notebook for model development
├── requirements.txt       # Python dependencies
├── README.md             # This file
```

## Model Training

To retrain the model with your own data:

1. **Prepare your dataset**
   - Format: CSV file with 'text' and 'emotion' columns

2. **Run the training notebook**
   ```bash
   jupyter notebook notebooks/app.ipynb
   ```

3. **Key training steps**:
   - Data loading and exploration
   - Text preprocessing and tokenization
   - Handling class imbalance with imblearn
   - Model architecture definition
   - Training with validation split
   - Model evaluation and saving

## API Usage

The app also supports programmatic usage:

```python
import joblib as jb
import tensorflow as tf
from tensorflow.keras.preprocessing.sequence import pad_sequences

# Load saved components
model = tf.keras.models.load_model("emotion_model.keras")
tokenizer = jb.load("tokenizer.jb")
label_encoder = jb.load("label_encoder.jb")

# Predict emotion
def predictor(text):
    processed_text = preprocess_text(text)
    sequence = tokenizer.texts_to_sequences([processed_text])
    padded_sequence = pad_sequences(sequence, maxlen=100, padding='post')
    prediction = model.predict(padded_sequence)
    predicted_label = label_encoder.inverse_transform([np.argmax(prediction)])
    return predicted_label[0]
```

## Performance Metrics

- **Accuracy**: ~97% on test dataset
- **Precision**: Varies by emotion class (0.75-0.92)
- **Recall**: Balanced across emotions with imblearn
- **F1-Score**: Weighted average of 0.83

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Create a Pull Request

## Troubleshooting

**Common Issues:**

- **Memory errors**: Reduce batch size or use model checkpointing
- **Slow predictions**: Ensure TensorFlow is using GPU if available
- **Import errors**: Verify all dependencies are installed correctly
- **Streamlit not loading**: Check if port 8501 is available

## Future Enhancements

- Support for multiple languages
- Real-time sentiment analysis
- Integration with social media APIs
- Mobile app development
- Advanced visualization dashboards
- Emotion intensity scoring

## License

This project is for educational and demonstration purposes.

## Acknowledgments

- TensorFlow and Keras teams for the deep learning framework
- Streamlit for the excellent web app framework
- Contributors to the imbalanced-learn library
- Open-source emotion datasets used for training

**Note**: This application is for research and educational purposes. Emotion detection accuracy may vary based on text complexity and context.