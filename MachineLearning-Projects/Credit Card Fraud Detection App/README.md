# Credit Card Fraud Detection App

A machine learning-powered application that predicts the likelihood of credit card transaction fraud based on various transaction and customer attributes.

## Overview

This application uses advanced machine learning algorithms to analyze credit card transactions in real-time and determine whether they are potentially fraudulent. The model considers multiple factors including transaction details, geographical information, temporal patterns, and customer demographics to make accurate predictions.

## Features

- **Real-time Fraud Detection**: Instantly analyze transactions for potential fraud
- **Comprehensive Input Analysis**: Considers multiple data points for accurate predictions
- **Geographic Analysis**: Uses location data to identify suspicious transaction patterns
- **Temporal Pattern Recognition**: Analyzes transaction timing for anomaly detection
- **User-friendly Interface**: Simple input form for transaction details

## Project Structure

```
Credit Card Fraud Detection/
├── app.py                      # Main Flask/Streamlit application
├── app.ipynb                   # Jupyter notebook for development/testing
├── fraud_detection_model.jb    # Trained machine learning model
├── label_encoder.jb            # Label encoder for categorical variables
├── dataset.csv                 # Training dataset
├── requirements.txt            # Python dependencies
└── README.md                   # This file
```

## Required Input Parameters

The application requires the following transaction details:

1. **Merchant Name**: Name of the merchant/business
2. **Category**: Transaction category (e.g., groceries, gas, restaurant)
3. **Transaction Amount**: Dollar amount of the transaction
4. **Latitude**: Customer's latitude coordinate
5. **Longitude**: Customer's longitude coordinate
6. **Merchant Latitude**: Merchant's latitude coordinate
7. **Merchant Longitude**: Merchant's longitude coordinate
8. **Transaction Hour**: Hour of the transaction (0-23)
9. **Transaction Day**: Day of the month (1-31)
10. **Transaction Month**: Month of the transaction (1-12)
11. **Gender**: Customer's gender
12. **Credit Card Number**: Credit card number (last 4 digits recommended for privacy)

## Installation

1. **Clone or download the project folder**:
   ```bash
   cd "Credit Card Fraud Detection"
   ```

2. **Install required dependencies**:
   ```bash
   pip install -r requirement.txt
   ```

# Fraud Detection App

This project uses a credit card fraud detection dataset.

📊 **Dataset:** 
```
https://www.kaggle.com/datasets/shuvomdhar/credit-card-fraud-detection-dataset
```

## Dependencies

The application uses the following Python libraries:

- **matplotlib**: Data visualization and plotting
- **imblearn**: Handling imbalanced datasets
- **lightgbm**: Gradient boosting framework for machine learning
- **scikit-learn (sklearn)**: Machine learning algorithms and utilities
- **geopy**: Geographic calculations and distance measurements
- **joblib**: Model serialization and loading

## Usage

1. **Run the application**:
   ```bash
   streamlit run app.py
   ```

2. **Input transaction details**: Enter all required parameters in the application interface

3. **Get prediction**: The model will analyze the transaction and provide:
   - Fraud probability score
   - Risk classification (Low/Medium/High)
   - Recommendation (Approve/Review/Decline)

## Model Information

- **Algorithm**: LightGBM (Light Gradient Boosting Machine)
- **Training Data**: Historical credit card transaction data with fraud labels
- **Features**: 12 input parameters including transaction, geographic, and demographic data
- **Performance**: Optimized for high precision and recall in fraud detection

## Geographic Features

The application calculates several geographic metrics:
- Distance between customer and merchant locations
- Transaction location patterns
- Geographic anomaly detection based on customer's typical transaction locations

## Temporal Analysis

The model analyzes temporal patterns including:
- Unusual transaction hours
- Day-of-month spending patterns
- Monthly transaction trends
- Time-based anomaly detection

## Security Considerations

- **Data Privacy**: Only store necessary transaction data
- **Credit Card Numbers**: Consider using only last 4 digits or tokenization
- **Secure Storage**: Ensure all sensitive data is properly encrypted
- **Access Control**: Implement proper authentication for production use

## Development and Testing

Use the included Jupyter notebook (`app.ipynb`) for:
- Model development and testing
- Data exploration and analysis
- Feature engineering experiments
- Model performance evaluation

## File Descriptions

- `fraud_detection_model.jb`: Serialized trained model ready for inference
- `label_encoder.jb`: Preprocessor for categorical variables
- `dataset.csv`: Historical transaction data used for model training
- `app.py`: Main application file with user interface and prediction logic
- `app.ipynb`: Development notebook for experimentation and analysis

## Contributing

To improve the model or add features:

1. Use the provided dataset for training
2. Experiment with new features in the Jupyter notebook
3. Update the model file after training improvements
4. Test thoroughly before deployment

## Troubleshooting

**Common Issues:**

- **Missing Dependencies**: Ensure all packages in `requirements.txt` are installed
- **Model Loading Errors**: Verify that `fraud_detection_model.jb` and `label_encoder.jb` are in the correct directory
- **Input Validation**: Ensure all required fields are properly formatted
- **Geographic Coordinates**: Verify latitude/longitude values are valid decimal degrees

## Performance Optimization

For better performance:
- Preload models at application startup
- Implement input validation and sanitization
- Consider caching for frequently accessed merchant data
- Monitor model performance and retrain periodically

## License

This project is for educational and commercial use. Please review applicable data privacy regulations before deployment.

## Support

For questions or issues:
1. Check the troubleshooting section
2. Review the Jupyter notebook for implementation details
3. Ensure all dependencies are correctly installed
4. Verify input data format and ranges