object Form5: TForm5
  Left = 698
  Top = 285
  Width = 600
  Height = 400
  Caption = #1057#1090#1074#1086#1088#1080#1090#1080' '#1090#1072#1073#1083#1080#1094#1102
  Color = clBtnFace
  Constraints.MaxHeight = 400
  Constraints.MaxWidth = 600
  Constraints.MinHeight = 400
  Constraints.MinWidth = 600
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 152
    Top = 0
    Width = 219
    Height = 20
    Caption = #1055#1086#1083#1103', '#1103#1082#1110' '#1073#1091#1076#1091#1090#1100' '#1074' '#1073#1072#1079#1110' '#1076#1072#1085#1080#1093
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 96
    Top = 344
    Width = 354
    Height = 13
    Caption = 
      #1055#1088#1080#1084#1110#1090#1082#1072': '#1089#1090#1086#1074#1087#1094#1110', '#1088#1103#1076#1082#1080', '#1072' '#1090#1072#1082#1086#1078' '#1111#1093' '#1082#1110#1083#1100#1082#1110#1089#1090#1100' '#1084#1086#1078#1085#1072' '#1079#1084#1110#1085#1102#1074#1072#1090#1080' '#1087 +
      #1086#1090#1110#1084
  end
  object Label3: TLabel
    Left = 200
    Top = 272
    Width = 126
    Height = 20
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1088#1103#1076#1082#1110#1074' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 112
    Top = 24
    Width = 76
    Height = 13
    Caption = #1053#1072#1079#1074#1072' '#1089#1090#1086#1074#1087#1094#1103
  end
  object Label5: TLabel
    Left = 336
    Top = 24
    Width = 51
    Height = 13
    Caption = #1058#1080#1087' '#1076#1072#1085#1080#1093
  end
  object CheckListBox1: TCheckListBox
    Left = 144
    Top = 92
    Width = 236
    Height = 153
    ItemHeight = 13
    TabOrder = 0
  end
  object Button1: TButton
    Left = 208
    Top = 64
    Width = 105
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 208
    Top = 248
    Width = 105
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 200
    Top = 294
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Button3: TButton
    Left = 200
    Top = 315
    Width = 121
    Height = 25
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
  object Edit2: TEdit
    Left = 80
    Top = 40
    Width = 145
    Height = 21
    TabOrder = 5
  end
  object ComboBox1: TComboBox
    Left = 288
    Top = 40
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 6
    Items.Strings = (
      #1062#1110#1083#1077' '#1095#1080#1089#1083#1086' - int'
      #1044#1088#1086#1073#1086#1074#1077' '#1095#1080#1089#1083#1086' - double'
      #1058#1077#1082#1089#1090' - string'
      #1051#1086#1075#1110#1095#1085#1080#1081' - bool')
  end
end
