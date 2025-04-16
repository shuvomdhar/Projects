# Automatic whatsapp message automation with twilio
# =====================================================

# step 1: install required libraries
from twilio.rest import Client
from datetime import datetime, timedelta
import time

# step 2: create a twilio account and get your account sid and auth token
account_sid = 'AC508764d63849999f6840e3ccf292777f'
auth_token = '3c54f1b847b439719b286277df54e77c'

client = Client(account_sid, auth_token)

# step 3: create a function to send a message
def send_message(recipient_number, message_body):
    try:
        message = client.messages.create(
            from_='whatsapp:+14155238886',
            body=message_body,
            to=f'whatsapp:{recipient_number}'
        )
        print(f'Message sent to {recipient_number} at {datetime.now()} successfully')
    except Exception as e:
        print(f'Error sending message to {recipient_number}: {str(e)}')

# step 4: user input
name = input("Enter your name: ")
recipient_number = input("Enter the recipient's number with country code: ")
message_body = input("Enter the message body: ")

# step 5: parse date/time and calculate delay
date_str = input("Enter the date (YYYY-MM-DD) to send the message: ")
time_str = input("Enter the time (HH:MM) to send the message: ")

# datetime
schedule_datetime = datetime.strptime(f'{date_str} {time_str}', '%Y-%m-%d %H:%M')
current_datetime = datetime.now()

# calculate delay
time_difference = schedule_datetime - current_datetime
delay_seconds = time_difference.total_seconds()

if delay_seconds <= 0:
    print("The specific time is in the past. Please enter a future date and time.")
else:
    print(f"Message scheduled to be sent to {name} at {schedule_datetime}.")

    # wait until the scheduled time
    time.sleep(delay_seconds)

    # send the message
    send_message(recipient_number, message_body)