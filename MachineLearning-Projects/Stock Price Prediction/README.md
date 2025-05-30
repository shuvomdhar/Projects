# Stock Price Prediction using LSTM

A machine learning web application that predicts stock prices using Long Short-Term Memory (LSTM) neural networks. Built with Streamlit for an interactive user interface and powered by deep learning techniques for time series forecasting.

## 🚀 Features

- **Real-time Stock Data**: Fetches live stock data using Yahoo Finance API
- **Advanced Technical Indicators**: Incorporates multiple technical analysis indicators including:
  - Simple Moving Average (SMA)
  - Exponential Moving Average (EMA)
  - Relative Strength Index (RSI)
  - Bollinger Bands
  - Daily Returns and Log Returns
  - Momentum and Volatility indicators
- **LSTM Neural Network**: Deep learning model for time series prediction
- **10-Day Price Forecasting**: Predicts stock prices for the next 10 days
- **Interactive Visualization**: Dynamic charts using Plotly
- **Model Caching**: Efficient model storage to avoid retraining
- **Multiple Stock Support**: Pre-configured with popular stocks (AAPL, MSFT, GOOGL, TSLA, AMZN)

## 📊 Supported Stocks

- **AAPL** - Apple Inc.
- **MSFT** - Microsoft Corporation
- **GOOGL** - Alphabet Inc.
- **TSLA** - Tesla Inc.
- **AMZN** - Amazon.com Inc.

## 🛠️ Installation

### Prerequisites

- Python 3.7 or higher
- pip package manager

### Setup

1. **Clone the repository** (if applicable):
   ```bash
   git clone [repository-url]
   cd MachineLearning-Projects
   ```

2. **Install required dependencies**:
   ```bash
   pip install -r requirements.txt
   ```

3. **Run the application**:
   ```bash
   streamlit run app.py
   ```

4. **Access the application**:
   Open your web browser and navigate to `http://localhost:8501`

## 📦 Dependencies

The project requires the following Python packages:

```
streamlit
yfinance
pandas
numpy
plotly
tensorflow
keras
scikit-learn
```

## 🏗️ Project Structure

```
MachineLearning-Projects/
├── app.py              # Main application file
├── requirements.txt    # Python dependencies
└── README.md          # Project documentation
```

## 🧠 Model Architecture

The LSTM model consists of:

- **Input Layer**: 60 time steps of historical stock data
- **LSTM Layer 1**: 50 units with return sequences
- **LSTM Layer 2**: 50 units without return sequences
- **Dense Layer 1**: 25 neurons
- **Output Layer**: 1 neuron for price prediction

### Technical Indicators Used

1. **SMA (50-day)**: Simple Moving Average for trend analysis
2. **EMA (50-day)**: Exponential Moving Average for recent price emphasis
3. **RSI (14-day)**: Relative Strength Index for momentum analysis
4. **Bollinger Bands**: Upper, Middle, and Lower bands for volatility analysis
5. **Momentum (4-day)**: Price momentum indicator
6. **Volatility (21-day)**: Rolling standard deviation

## 🎯 How It Works

1. **Data Fetching**: Retrieves 5 years of historical stock data from Yahoo Finance
2. **Feature Engineering**: Calculates technical indicators and preprocessing
3. **Data Normalization**: Scales data using MinMaxScaler for optimal neural network performance
4. **Sequence Preparation**: Creates 60-day sequences for LSTM input
5. **Model Training**: Trains LSTM network with 80/20 train-test split
6. **Prediction**: Generates 10-day forward predictions
7. **Visualization**: Displays results with interactive Plotly charts

## 📈 Usage

1. **Select Stock**: Choose from the dropdown menu of available stocks
2. **View Current Price**: See the latest stock price
3. **Train & Predict**: Click the button to train the model and generate predictions
4. **View Results**: Examine the predicted prices table and interactive chart

## ⚠️ Important Notes

- **Model Caching**: Models are cached to improve performance on repeated predictions
- **Training Time**: Initial model training may take a few minutes
- **Data Dependency**: Predictions depend on historical data quality and market conditions
- **No Financial Advice**: This tool is for educational purposes only and should not be used for actual trading decisions

## 🔧 Customization

### Adding New Stocks

To add new stocks, modify the `stock_list` in `app.py`:

```python
stock_list = ['AAPL', 'MSFT', 'GOOGL', 'TSLA', 'AMZN', 'YOUR_STOCK_SYMBOL']
```

### Adjusting Prediction Period

To change the prediction timeframe, modify the range in the prediction loop:

```python
for day in range(10):  # Change 10 to desired number of days
```

### Model Hyperparameters

Key parameters that can be tuned:

- `time_steps=60`: Historical data window
- `epochs=5`: Training iterations
- `batch_size=32`: Training batch size
- LSTM units: Currently set to 50 for both layers

## 📝 Model Performance

The model displays training loss as a performance metric. Lower loss values indicate better model performance on the test dataset.

## 🤝 Contributing

Feel free to contribute to this project by:

- Adding new technical indicators
- Implementing different neural network architectures
- Expanding stock symbol support
- Improving the user interface
- Adding model evaluation metrics

## 📄 License

This project is for educational and commercial use. Please review applicable data privacy regulations before deployment.

## ⚡ Performance Tips

- Models are cached automatically to avoid retraining
- Close unnecessary browser tabs when running to optimize memory usage
- For better predictions, ensure stable internet connection for data fetching

## 🔍 Troubleshooting

**Common Issues:**

1. **Import Errors**: Ensure all dependencies are installed via `pip install -r requirements.txt`
2. **Data Fetching Issues**: Check internet connection and Yahoo Finance API availability
3. **Memory Issues**: Reduce batch size or number of LSTM units if experiencing memory problems
4. **Slow Performance**: Consider reducing the number of epochs or using a smaller time window

---

**Disclaimer**: This application is for educational and research purposes only. Stock market predictions are inherently uncertain, and this tool should not be used as the sole basis for investment decisions. Always consult with financial advisors and conduct thorough research before making investment choices.